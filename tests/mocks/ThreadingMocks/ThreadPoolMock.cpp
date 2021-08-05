#include "ThreadPoolMock.h"
#include <Threading/ThreadPool.h>
#include <Threading/Task.h>

namespace ThreadingMocks
{
    ThreadPoolMock::ThreadPoolMock()
        :Threading::ThreadPool("mock")
    {
    }

    ThreadPoolMock::~ThreadPoolMock()
    {
    }

    void ThreadPoolMock::submit(Task task)
    {
        task();
    }
}