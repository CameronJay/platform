#include "../Semaphore.h"

namespace Threading
{
    struct SemaphoreProperties
    {
        SemaphoreProperties(uint32_t initial, uint32_t max)
        {

        }

    };

    Semaphore::Semaphore(uint32_t initial, uint32_t max)
        :properties_(new SemaphoreProperties(initial, max))
    {

    }

    Semaphore::~Semaphore()
    {

    }

    bool Semaphore::init()
    {

    }

    bool Semaphore::wait()
    {

    }

    bool Semaphore::timedWait(uint32_t timeout)
    {

    }

    bool Semaphore::post(uint32_t count)
    {

    }

    bool Semaphore::destroy()
    {

    }
}