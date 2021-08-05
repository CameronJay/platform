#pragma once

#include <string>

namespace MessageBus
{
    class Message
    {
    public:
        Message(std::string const& text);
        Message(char const character);
        virtual ~Message();
        std::string const& text() const { return text_; }

    private:
        std::string text_;
    };
}
