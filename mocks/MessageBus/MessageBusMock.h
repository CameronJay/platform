#pragma once

#include <MessageBus/MessageBus.h>

namespace MessageBusMocks
{
    class MessageBusMock : public MessageBus::MessageBus
    {
    public:
        MessageBusMock(Threading::DispatchQueue* dispatchQueue);
        virtual ~MessageBusMock();

    };

}