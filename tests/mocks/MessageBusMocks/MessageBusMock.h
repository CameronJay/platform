#pragma once

#include <MessageBus/MessageBus.h>

namespace MessageBusMocks
{
    class MessageBusMock : public MessageBus::MessageBus
    {
    public:
        MessageBusMock();
        virtual ~MessageBusMock();

    };

}