#pragma once

#include <limits>       // std::numeric_limits
#include <memory>
#include <string>
#include <cstdint>

namespace Threading
{
    struct SemaphoreProperties;

    class Semaphore
    {
    public:
        Semaphore(uint32_t initial = 0, uint32_t max = std::numeric_limits<uint32_t>::max());
        virtual ~Semaphore();

        bool init();
        bool wait();
        bool timedWait(uint32_t timeout = -1 /* milliseconds */);
        bool post(uint32_t count = 1 /* how many times to post */);
        bool destroy();

    private:
        std::shared_ptr<SemaphoreProperties> properties_; // referenced in cpp for specific platform
    };
}