#pragma once

#include <string>
#include <memory>
#include <MessageBus/MessageBusObserver.h>

namespace Debug
{
    class Debugger : public MessageBus::MessageBusObserver
    {
    public:
        Debugger(MessageBus::MessageBus* bus);
        virtual ~Debugger();

        // MessageBusObserver
        virtual void update(MessageBus::Message const& message);

        // Debugger
        MessageBus::MessageBus* const bus() const { return bus_; }

    private:
        MessageBus::MessageBus* bus_;
    };
}
