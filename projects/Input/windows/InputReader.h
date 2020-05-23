#pragma once

#include <string>
#include <memory>
#include <MessageBus/MessageBusObserver.h>

namespace Input
{
    class InputReader : public MessageBus::MessageBusObserver
    {
    public:
        InputReader(MessageBus::MessageBus* bus);
        virtual ~InputReader();

        void inputLoop();

        // MessageBusObserver
        virtual void start();
        virtual void stop();
        virtual void update();

        // Debugger
        MessageBus::MessageBus* const bus() const { return bus_; }

    private:
        static const char loopBreaker_ = 'd';
        MessageBus::MessageBus* bus_;
        bool loop_;
    };
}
