#include "MessageBusMock.h"
#include <Threading/DispatchQueue.h>
#include <Threading/Task.h>

namespace MessageBusMocks
{
    MessageBusMock::MessageBusMock(Threading::DispatchQueue* dispatchQueue)
        :MessageBus(dispatchQueue)
    {
    }

    MessageBusMock::~MessageBusMock()
    {
    }

}