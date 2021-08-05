#include "pch.h"
#include "MessageBusTest.h"
#include <chrono>
#include <thread>

#define protected public
#define private public
#include <Threading/ThreadPool.h>
#include <Threading/Semaphore.h>
#include <ThreadingMocks/ThreadPoolMock.h>
#include <MessageBus/MessageBus.h>
#include <MessageBusMocks/MessageBusObserverMock.h>
#undef protected
#undef private

namespace MessageBusTests
{
    TEST_F(MessageBusTest, testAttachAndDetach)
    {
        std::shared_ptr<MessageBus::MessageBus> bus(new MessageBus::MessageBus);
        size_t count = 0;
        size_t size = bus->observers_.size();
        EXPECT_EQ(count, size);

        std::shared_ptr<MessageBusMocks::MessageBusObserverMock>
            mockObserver(new MessageBusMocks::MessageBusObserverMock(bus));

        bus->attach(mockObserver.get());
        count = 1;
        size = bus->observers_.size();
        EXPECT_EQ(count, size);

        bus->detach(mockObserver.get());
        count = 0;
        size = bus->observers_.size();
        EXPECT_EQ(count, size);
    }

    TEST_F(MessageBusTest, testReceiveAndNotify)
    {
        std::shared_ptr<MessageBus::MessageBus> bus(new MessageBus::MessageBus);

        std::shared_ptr<MessageBusMocks::MessageBusObserverMock>
            mockObserver(new MessageBusMocks::MessageBusObserverMock(bus));

        std::shared_ptr<ThreadingMocks::ThreadPoolMock> threadPoolMock(new ThreadingMocks::ThreadPoolMock);

        bus->attach(mockObserver.get());
        std::string msg = "test";
        MessageBus::Message message(msg);

        bus->threadPool_ = threadPoolMock;
        bus->receive(message);

        const char* expectedCharArray = msg.c_str();
        const char* actualCharArray = bus->messages_[0].text().c_str();

        EXPECT_STREQ(expectedCharArray, actualCharArray);

        const char* actualNotifiedCharArray = mockObserver->notifiedMessages_[0].text().c_str();

        EXPECT_STREQ(expectedCharArray, actualNotifiedCharArray);
    }
}