#include "MessageBusObserverMock.h"

namespace MessageBusMocks
{

    MessageBusObserverMock::MessageBusObserverMock(std::shared_ptr<MessageBus::MessageBus> bus)
        :MessageBus::MessageBusObserver(bus)
    {
    }

    MessageBusObserverMock::~MessageBusObserverMock()
    {
    }

    void MessageBusObserverMock::update()
    {
        notifiedMessages_ = bus_->messages();
    }

}