#include <iostream>
#include <memory>
#include <Input/InputReader.h>
#include <MessageBus/Message.h>
#include <MessageBus/MessageBus.h>
#include <Threading/DispatchQueue.h>
#include "Debugger/Debugger.h"


int main()
{
    std::string input = "";
    std::string name = "bus";
    std::shared_ptr<Threading::DispatchQueue> dispatchQueue(new Threading::DispatchQueue(name, 1));
    std::shared_ptr<MessageBus::MessageBus> bus(new MessageBus::MessageBus(dispatchQueue.get()));
    std::shared_ptr<Debug::Debugger> debugger(new Debug::Debugger(bus.get()));
    std::shared_ptr<Input::InputReader> inputter(new Input::InputReader(bus.get()));


    debugger->start();
    inputter->start();

    return 0;
}