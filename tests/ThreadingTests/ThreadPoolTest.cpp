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
    }

    TEST_F(ThreadPoolTest, testSubmit)
    {
    }

    void ThreadPoolTest::singleThreadedAssert()
    {
    }
}