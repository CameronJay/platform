#include "pch.h"
#include "DispatchQueueTest.h"
#include <Threading/DispatchQueue.h>
#include <Threading/Task.h>


namespace ThreadingTests
{
    const std::string DispatchQueueTest::name_ = "DispatchQueueTest";

    const size_t DispatchQueueTest::countZero_ = 0;
    const size_t DispatchQueueTest::countOne_ = 1;
    const size_t DispatchQueueTest::countThree_ = 3;

    bool DispatchQueueTest::testOneRan_ = false;
    bool DispatchQueueTest::testTwoRan_ = false;
    bool DispatchQueueTest::testThreeRan_ = false;

    std::timed_mutex DispatchQueueTest::assertMutex_;
    std::timed_mutex DispatchQueueTest::testMutex_;

    TEST_F(DispatchQueueTest, testZeroThreads)
    {
        Task task1 = std::bind(&DispatchQueueTest::testFunction1, this);
        Task task2 = std::bind(&DispatchQueueTest::testFunction2, this);
        Task task3 = std::bind(&DispatchQueueTest::testFunction3, this);

        Threading::DispatchQueue queue(name_, countZero_);
        queue.push(task1);
        queue.push(task2);
        queue.push(task3);

        assertMutex_.lock();
        assertMutex_.try_lock_for(std::chrono::milliseconds(100));
        EXPECT_EQ(false, testOneRan_);
        EXPECT_EQ(false, testTwoRan_);
        EXPECT_EQ(false, testThreeRan_);
        testMutex_.unlock();
        assertMutex_.try_lock_for(std::chrono::milliseconds(100));
        EXPECT_EQ(false, testOneRan_);
        EXPECT_EQ(false, testTwoRan_);
        EXPECT_EQ(false, testThreeRan_);
        testMutex_.unlock();
        assertMutex_.try_lock_for(std::chrono::milliseconds(100));
        EXPECT_EQ(false, testOneRan_);
        EXPECT_EQ(false, testTwoRan_);
        EXPECT_EQ(false, testThreeRan_);
        testMutex_.unlock();
        assertMutex_.unlock();
    }

    TEST_F(DispatchQueueTest, testOneThread)
    {
        Task task1 = std::bind(&DispatchQueueTest::testFunction1, this);
        Task task2 = std::bind(&DispatchQueueTest::testFunction2, this);
        Task task3 = std::bind(&DispatchQueueTest::testFunction3, this);

        Threading::DispatchQueue queue(name_, countOne_);
        queue.push(task1);
        queue.push(task2);
        queue.push(task3);

        assertMutex_.lock();
        assertMutex_.try_lock_for(std::chrono::milliseconds(100));
        EXPECT_EQ(true, testOneRan_);
        EXPECT_EQ(false, testTwoRan_);
        EXPECT_EQ(false, testThreeRan_);
        testMutex_.unlock();
        assertMutex_.try_lock_for(std::chrono::milliseconds(100));
        EXPECT_EQ(true, testOneRan_);
        EXPECT_EQ(true, testTwoRan_);
        EXPECT_EQ(false, testThreeRan_);
        testMutex_.unlock();
        assertMutex_.try_lock_for(std::chrono::milliseconds(100));
        EXPECT_EQ(true, testOneRan_);
        EXPECT_EQ(true, testTwoRan_);
        EXPECT_EQ(true, testThreeRan_);
        testMutex_.unlock();
        assertMutex_.unlock();
    }

    void DispatchQueueTest::testFunction1()
    {
        testMutex_.lock();
        testOneRan_ = true;
        assertMutex_.unlock();
    }

    void DispatchQueueTest::testFunction2()
    {
        testMutex_.lock();
        testTwoRan_ = true;
        assertMutex_.unlock();
    }

    void DispatchQueueTest::testFunction3()
    {
        testMutex_.lock();
        testThreeRan_ = true;
        assertMutex_.unlock();
    }

    void DispatchQueueTest::resetFlags()
    {
        testOneRan_ = false;
        testTwoRan_ = false;
        testThreeRan_ = false;
    }
}