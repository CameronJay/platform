#include "Debugger.h"
#include <iostream>
#include <MessageBus/MessageBus.h>

Debug::Debugger::Debugger(MessageBus::MessageBus* bus)
:bus_(bus)
{
}

Debug::Debugger::~Debugger()
{
}

void Debug::Debugger::start()
{
    bus_->attach(this);
}

void Debug::Debugger::stop()
{
    bus_->detach(this);
}

void Debug::Debugger::update()
{
    MessageBus::Message message = bus_->messages().back();
    std::cout << "Debugger received: " << message.text() << std::endl;
}
