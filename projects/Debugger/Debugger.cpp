#include "Debugger.h"
#include <iostream>
#include <MessageBus/MessageBus.h>

Debug::Debugger::Debugger(MessageBus::MessageBus* bus)
:bus_(bus)
{
    bus_->attach(this);
}

Debug::Debugger::~Debugger()
{
    bus_->detach(this);
}

void Debug::Debugger::update(MessageBus::Message const& message)
{
    std::cout << "Debugger received: " << message.text() << std::endl;
}
