#include "Message.h"

namespace MessageBus
{

    Message::Message(std::string const& text)
        :text_(text)
    {
    }

    Message::Message(char const character)
        : text_(1, character)
    {
    }

    Message::~Message()
    {
    }
}