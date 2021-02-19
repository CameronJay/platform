#pragma once

#include <string>
#include <memory>
#include <mutex>
#include <MessageBus/MessageBusObserver.h>

namespace Threading { class ThreadPool; }
namespace Debug { class Debugger; }
namespace Input { class InputReader; }
namespace MessageBus { class MessageBus; }

namespace App
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void start();

    private:
        static const std::string name_;
        std::shared_ptr<Threading::ThreadPool> pool_;
        std::shared_ptr<MessageBus::MessageBus> bus_;
        std::shared_ptr<Debug::Debugger> debugger_;
        std::shared_ptr<Input::InputReader> inputReader_;
    };
}
