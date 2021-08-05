#pragma once

#include "Message.h"
#include <memory>

namespace MessageBus
{
    class MessageBus;

    class MessageBusObserver
    {
    public:
        MessageBusObserver(std::shared_ptr<MessageBus> bus);

        virtual ~MessageBusObserver();

        virtual void start() = 0;
        virtual void stop() = 0;
        virtual void update() = 0;
        MessageBus* const bus() const { return bus_.get(); }

    protected:
        std::shared_ptr<MessageBus> bus_;
    };
}