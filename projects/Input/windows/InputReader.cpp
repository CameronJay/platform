#include "../InputReader.h"
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
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
        char input = 'e';
        DWORD oldConsoleMode;
        DWORD newConsoleMode;
        DWORD numberOfRecords;
        DWORD const bufferLength = 1024;
        INPUT_RECORD buffer[bufferLength];
        DWORD numRead = 0;

        HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);

        GetConsoleMode(handle, &oldConsoleMode);

        // Enable the window and mouse input events. 

        newConsoleMode = ENABLE_WINDOW_INPUT;
        SetConsoleMode(handle, newConsoleMode);

        while (loop_)
        {
            ReadConsoleInput(handle, buffer, bufferLength, &numRead);

            for (DWORD i = 0; i < numRead; ++i)
            {
                switch (buffer[i].EventType)
                {
                case KEY_EVENT:
                    input = buffer[i].Event.KeyEvent.uChar.AsciiChar;
                    break;

                default:
                    break;
                }
            }

            MessageBus::Message message(input);
            bus_->receive(message);
        }

        SetConsoleMode(handle, oldConsoleMode);
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