/*
Platform
Cameron Dempsey
James Tubbs
*/

#include <iostream>
#include <memory>
#include <Input/InputReader.h>
#include <MessageBus/Message.h>
#include <MessageBus/MessageBus.h>
#include "Debugger/Debugger.h"


int main()
{
    std::string input = "";
    std::shared_ptr<MessageBus::MessageBus> bus(new MessageBus::MessageBus());
    std::shared_ptr<Debug::Debugger> debugger(new Debug::Debugger(bus.get()));
    std::shared_ptr<Input::InputReader> inputter(new Input::InputReader(bus.get()));

    debugger->start();
    inputter->start();

    return 0;
}