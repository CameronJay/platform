#include "MessageBusObserver.h"

namespace MessageBus
{

    MessageBusObserver::MessageBusObserver(std::shared_ptr<MessageBus> bus)
        :bus_(bus)
    {
    }

    MessageBusObserver::~MessageBusObserver()
    {
    }

}