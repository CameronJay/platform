#pragma once

#include "Message.h"
#include <list>
#include <vector>

namespace MessageBus
{
    class MessageBusObserver;

    class MessageBus
    {
    public:
        typedef std::list<MessageBusObserver*> ObserverList;
        typedef std::vector<Message> MessageList;

        MessageBus();
        virtual ~MessageBus();

        void attach(MessageBusObserver* observer);
        void detach(MessageBusObserver* observer);

        void receive(Message const& message);
    protected:
        void notify();

    private:
        ObserverList observers_;
        MessageList messages_;
    };

}