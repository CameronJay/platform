#pragma once

#include "Message.h"

namespace MessageBus
{
    class MessageBus;

    class MessageBusObserver
    {
    public:
        MessageBusObserver();
        virtual ~MessageBusObserver();

        virtual void start() = 0;
        virtual void stop() = 0;
        virtual void update(Message const& message) = 0;

    };

}