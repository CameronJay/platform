#include "Message.h"

namespace MessageBus
{

    Message::Message(std::string const& text)
    :text_(text)
    {
    }

    Message::~Message()
    {
    }
}