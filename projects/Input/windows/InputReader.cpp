#include "../InputReader.h"
#include <conio.h>
#include <iostream>
#include <MessageBus/MessageBus.h>

namespace Input
{
    InputReader::InputReader(std::shared_ptr<MessageBus::MessageBus> bus)
        :MessageBus::MessageBusObserver(bus),
        loop_(true)
    {
    }

    InputReader::~InputReader()
    {
        stop();
    }

    void InputReader::inputLoop()
    {
        char input;
        while (loop_)
        {
            input = _getch();
            MessageBus::Message message(input);
            bus_->receive(message);
        }
    }

    void InputReader::start()
    {
        bus_->attach(this);
        inputLoop();
    }

    void InputReader::stop()
    {
        bus_->detach(this);
    }

    void InputReader::update()
    {
        MessageBus::Message message = bus_->messages().back();
        std::cout << "InputReader received: " << message.text() << std::endl;

        if (message.text()[0] == loopBreaker_)
        {
            loop_ = false;
        }
    }
}