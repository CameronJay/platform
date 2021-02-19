#pragma once

#include <MessageBus/MessageBusObserver.h>

namespace MessageBusMocks
{

    class MessageBusObserverMock : public MessageBus::MessageBusObserver
    {
    public:
        MessageBusObserverMock(std::shared_ptr<MessageBus::MessageBus> bus);
        virtual ~MessageBusObserverMock();

        virtual void start() {}
        virtual void stop() {}
        virtual void update() {}

    };

}