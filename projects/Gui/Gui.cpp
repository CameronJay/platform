#include "Gui.h"
#include <conio.h>
#include <iostream>
#include <MessageBus/MessageBus.h>

#include <stdio.h>
#include <stdlib.h>
#include <glfw-3.3.3\include\GLFW/glfw3.h>

namespace Gui
{
    Gui::Gui(std::shared_ptr<MessageBus::MessageBus> bus)
        :MessageBus::MessageBusObserver(bus)
    {
    }

    Gui::~Gui()
    {
        stop();
    }

    void Gui::start()
    {
        bus_->attach(this);


    }

    void Gui::stop()
    {
        bus_->detach(this);
    }

    void Gui::update()
    {
        MessageBus::Message message = bus_->messages().back();
        std::cout << "Gui received: " << message.text() << std::endl;

    }
}