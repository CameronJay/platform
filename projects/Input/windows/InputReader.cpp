#include "InputReader.h"
#include <conio.h>
#include <iostream>
#include <MessageBus/MessageBus.h>

Input::InputReader::InputReader(MessageBus::MessageBus* bus)
    :bus_(bus),
    loop_(true)
{
}

Input::InputReader::~InputReader()
{
    stop();
}

void Input::InputReader::inputLoop()
{
    char input;
    while (loop_)
    {
        input = _getch();
        MessageBus::Message message(input);
        bus_->receive(message);
    }
}

void Input::InputReader::start()
{
    bus_->attach(this);
    inputLoop();
}

void Input::InputReader::stop()
{
    bus_->detach(this);
}

void Input::InputReader::update()
{
    std::cout << "InputReader received: " << std::endl;

    //if (message.text()[0] == loopBreaker_)
    //{
    //    loop_ = false;
    //}
}
