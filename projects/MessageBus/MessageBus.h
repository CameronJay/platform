#pragma once

#include "Message.h"
#include <list>

namespace MessageBus
{
    class MessageBusObserver;

    class MessageBus
    {
    public:
        typedef std::list<MessageBusObserver*> ObserverList;

        MessageBus();
        virtual ~MessageBus();

        void attach(MessageBusObserver* observer);
        void detach(MessageBusObserver* observer);

    protected:
        void notify(Message const& message);

    private:
        ObserverList observers_;
    };

}