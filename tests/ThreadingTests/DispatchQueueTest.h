#pragma once

#include <mutex>

namespace ThreadingTests
{
    class DispatchQueueTest : public ::testing::Test
    {
    public:
        void testFunction1();
        void testFunction2();
        void testFunction3();
    protected:
        void resetFlags();

        static const std::string name_;

        static const size_t countZero_;
        static const size_t countOne_;
        static const size_t countThree_;

        static bool testOneRan_;
        static bool testTwoRan_;
        static bool testThreeRan_;

        static std::timed_mutex assertMutex_;
        static std::timed_mutex testMutex_;
    };

}