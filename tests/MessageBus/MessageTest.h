#pragma once

namespace MessageBusTests
{
    class MessageTest : public ::testing::Test
    {
    protected:
        static const std::string testString_;
        static const char testChar_;
        static const MessageBus::Message stringMessage_;
        static const MessageBus::Message charMessage_;
    };
}
