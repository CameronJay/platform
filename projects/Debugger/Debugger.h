#pragma once

#include <string>
#include <memory>
#include <mutex>
#include <MessageBus/MessageBusObserver.h>

namespace Debug
{
    class Debugger : public MessageBus::MessageBusObserver
    {
    public:
        Debugger(std::shared_ptr<MessageBus::MessageBus> bus);
        virtual ~Debugger();

        // MessageBusObserver
        virtual void start();
        virtual void stop();
        virtual void update();

        // Debugger
        void wait();
        MessageBus::MessageBus* const bus() const { return bus_.get(); }

    private:
        std::shared_ptr<MessageBus::MessageBus> bus_;
        static uint32_t idCounter_;
        uint32_t id_;
        std::mutex idLock_;
    };
}
