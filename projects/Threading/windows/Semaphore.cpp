#include "../Semaphore.h"
#include <Windows.h>

namespace Threading
{
    struct SemaphoreProperties
    {
        SemaphoreProperties(uint32_t initial, uint32_t max)
            :semaphore_(NULL),
            initial_(static_cast<LONG>(initial)),
            max_(static_cast<LONG>(max))
        {
        }

        HANDLE semaphore_;
        LONG   initial_;
        LONG   max_;
    };

    Semaphore::Semaphore(uint32_t initial, uint32_t max)
        :properties_(new SemaphoreProperties(initial, max))
    {
    }

    Semaphore::~Semaphore()
    {
        destroy();
    }

    bool Semaphore::init()
    {
        if (properties_->semaphore_ == NULL)
        {
            properties_->semaphore_ = CreateSemaphore(NULL, properties_->initial_, properties_->max_, NULL);
        }
        return (properties_->semaphore_ != NULL);
    }

    bool Semaphore::wait()
    {
        bool ret = false;
        if (properties_->semaphore_ != NULL)
        {
            ret = (WaitForSingleObject(properties_->semaphore_, INFINITE) == WAIT_OBJECT_0);
        }
        return ret;
    }

    bool Semaphore::timedWait(uint32_t timeout)
    {
        bool ret = false;
        if (properties_->semaphore_ != NULL)
        {
            ret = (WaitForSingleObject(properties_->semaphore_, timeout) == WAIT_OBJECT_0);
        }
        return ret;
    }

    bool Semaphore::post(uint32_t count)
    {
        bool ret = false;
        if (properties_->semaphore_ != NULL)
        {
            ret = static_cast<int>(ReleaseSemaphore(properties_->semaphore_, static_cast<LONG>(count), NULL));
        }
        return ret;
    }

    bool Semaphore::destroy()
    {
        bool ret = false;
        if (properties_->semaphore_ != NULL)
        {
            ret = CloseHandle(properties_->semaphore_);
            if (ret)
            {
                properties_->semaphore_ = NULL;
            }
        }
        return ret;
    }
}