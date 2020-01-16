#pragma once

#include <string>

namespace MessageBus
{
    class Message
    {
    public:
        Message(std::string const& text);
        virtual ~Message();
        std::string const& text() const { return text_; }
    
    private:
        std::string const text_;
    };
}
