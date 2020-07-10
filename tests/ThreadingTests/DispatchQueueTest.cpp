#include "pch.h"
#include "DispatchQueueTest.h"
#include <Threading/DispatchQueue.h>
#include <Threading/Task.h>


namespace ThreadingTests
{
    TEST_F(DispatchQueueTest, test)
    {
        std::string name = "Test";
        size_t count = 3;
        Threading::DispatchQueue queue(name, count);
        Task task = std::bind(&DispatchQueueTest::testFunction, this);
        queue.push(task);
    }

    void DispatchQueueTest::testFunction()
    {

    }
}