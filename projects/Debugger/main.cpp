#include <iostream>
#include <memory>
#include <Input/InputReader.h>
#include <MessageBus/Message.h>
#include <MessageBus/MessageBus.h>
#include <Threading/ThreadPool.h>
#include "Debugger/Debugger.h"


int main()
{
    std::string name = "Main";
    std::shared_ptr<Threading::ThreadPool> queue(new Threading::ThreadPool(name, 2));

    std::shared_ptr<MessageBus::MessageBus> bus(new MessageBus::MessageBus());
    std::shared_ptr<Debug::Debugger> debugger(new Debug::Debugger(bus));
    std::shared_ptr<Input::InputReader> inputter(new Input::InputReader(bus));

    Task task = std::bind(&Debug::Debugger::start, debugger);
    queue->submit(task);
    queue->start();
    inputter->start();

    return 0;
}