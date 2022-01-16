#include "pch.h"
#include "ThreadPoolTest.h"
#include <Threading/Task.h>

#define protected public
#define private public
#include <Threading/ThreadPool.h>
#undef protected
#undef private

namespace ThreadingTests
{
    TEST_F(ThreadPoolTest, testStartAndStop)
    {
        // single threaded
        {
            std::string name = "test";
            size_t count = 1; // just one.
            Threading::ThreadPool singleThreadedPool(name, count);

            singleThreadedPool.start();
            bool running = singleThreadedPool.running_;
            EXPECT_EQ(true, running);
            size_t size = singleThreadedPool.threads_.size();
            EXPECT_EQ(count, size);

            singleThreadedPool.stop();
            running = singleThreadedPool.running_;
            EXPECT_EQ(false, running);
            size = singleThreadedPool.threads_.size();
            EXPECT_EQ(count, size);
        }
        // multi threaded
        {
            std::string name = "test";
            size_t count = 3; // just more than one.
            Threading::ThreadPool multiThreadedPool(name, count);

            multiThreadedPool.start();
            bool running = multiThreadedPool.running_;
            EXPECT_EQ(true, running);
            size_t size = multiThreadedPool.threads_.size();
            EXPECT_EQ(count, size);

            multiThreadedPool.stop();
            running = multiThreadedPool.running_;
            EXPECT_EQ(false, running);
            size = multiThreadedPool.threads_.size();
            EXPECT_EQ(count, size);
        }
    }

    TEST_F(ThreadPoolTest, testSubmit)
    {
        std::string name = "test";
        size_t count = 1; // just one.
        Threading::ThreadPool pool(name, count);

        size_t actualSize = pool.taskQueue_.size();
        size_t expectedSize = 0;
        EXPECT_EQ(actualSize, expectedSize);

        Task task = 0;
        pool.submit(task);
        actualSize = pool.taskQueue_.size();
        expectedSize = 1;
        EXPECT_EQ(actualSize, expectedSize);
    }
}