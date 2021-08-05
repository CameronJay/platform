#pragma once

#include <string>
#include <memory>
#include <MessageBus/MessageBusObserver.h>

namespace Gui
{
    class Gui : public MessageBus::MessageBusObserver
    {
    public:
        Gui(std::shared_ptr<MessageBus::MessageBus> bus);
        virtual ~Gui();

        // MessageBusObserver
        virtual void start();
        virtual void stop();
        virtual void update();

    private:

    };
}
