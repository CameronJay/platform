#pragma once

#include "Message.h"
#include <list>
#include <vector>

namespace Threading
{
    class DispatchQueue;
}

namespace MessageBus
{
    class MessageBusObserver;

    class MessageBus
    {
    public:
        typedef std::list<MessageBusObserver*> ObserverList;
        typedef std::vector<Message> MessageList;

        MessageBus(Threading::DispatchQueue* dispatchQueue);
        virtual ~MessageBus();

        void attach(MessageBusObserver* observer);
        void detach(MessageBusObserver* observer);

        void receive(Message const& message);
        MessageList const messages() const { return messages_; }

    protected:
        void notify();

    private:
        ObserverList observers_;
        MessageList messages_;

        Threading::DispatchQueue* dispatchQueue_;
    };

}