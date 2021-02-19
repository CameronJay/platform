#pragma once

#include <string>
#include <memory>
#include <MessageBus/MessageBusObserver.h>

namespace Input
{
    class InputReader : public MessageBus::MessageBusObserver
    {
    public:
        InputReader(std::shared_ptr<MessageBus::MessageBus> bus);
        virtual ~InputReader();

        void inputLoop();

        // MessageBusObserver
        virtual void start();
        virtual void stop();
        virtual void update();

    private:
        static const char loopBreaker_ = 'd';
        bool loop_;
    };
}
