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

}