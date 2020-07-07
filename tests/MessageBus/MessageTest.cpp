#include "pch.h"
#include "MessageTest.h"
#include <MessageBus/Message.h>

namespace MessageBusTests
{
    const std::string MessageTest::testString_ = "test";
    const char MessageTest::testChar_ = 't';
    const MessageBus::Message MessageTest::stringMessage_(MessageTest::testString_);
    const MessageBus::Message MessageTest::charMessage_(MessageTest::testChar_);

    TEST_F(MessageTest, testStringMessage) 
    {
        const char* expectedCharArray = MessageTest::testString_.c_str();
        const char* actualCharArray = stringMessage_.text().c_str();

        EXPECT_STREQ(expectedCharArray, actualCharArray);
    }

    TEST_F(MessageTest, testCharMessage)
    {
        char actualChar = charMessage_.text()[0];

        EXPECT_EQ(MessageTest::testChar_, actualChar);
    }
}