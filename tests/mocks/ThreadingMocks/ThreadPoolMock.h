#pragma once

#include <Threading/ThreadPool.h>

namespace ThreadingMocks
{
    class ThreadPoolMock : public Threading::ThreadPool
    {
    public:
        ThreadPoolMock();
        virtual ~ThreadPoolMock();
        virtual void start() {}
        virtual void stop() {}
        virtual void submit(Task task);
    };
}