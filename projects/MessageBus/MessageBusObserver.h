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

        virtual void update(Message const& message) = 0;

    };

}