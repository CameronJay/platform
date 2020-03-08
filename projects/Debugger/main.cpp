/*
Platform
Cameron Dempsey
James Tubbs
*/

#include <iostream>
#include <memory>
#include <MessageBus/Message.h>
#include <MessageBus/MessageBus.h>
#include "Debugger/Debugger.h"

static const std::string close = "CLOSE";

int main()
{
    std::string input = "";
    std::shared_ptr<MessageBus::MessageBus> bus(new MessageBus::MessageBus());
    std::shared_ptr<Debug::Debugger> debugger(new Debug::Debugger(bus.get()));

    while (input != close)
    {
        std::cin >> input;
        MessageBus::Message message(input);
        bus->receive(message);
    } 
}