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
#include <Threading/DispatchQueue.h>
#include "Debugger/Debugger.h"


int main()
{
    std::string name = "Main";
    std::shared_ptr<Threading::DispatchQueue> queue(new Threading::DispatchQueue(name, 2));

    std::shared_ptr<MessageBus::MessageBus> bus(new MessageBus::MessageBus());
    std::shared_ptr<Debug::Debugger> debugger(new Debug::Debugger(bus.get()));
    std::shared_ptr<Input::InputReader> inputter(new Input::InputReader(bus.get()));

    Task task = std::bind(&Debug::Debugger::start, debugger);
    queue->push(task);
    inputter->start();

    return 0;
}