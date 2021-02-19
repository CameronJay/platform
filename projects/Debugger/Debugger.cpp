#include "Debugger.h"
#include <cstdio>
#include <chrono> // std::chrono::microseconds
#include <thread> // std::this_thread::sleep_for
#include <MessageBus/MessageBus.h>

namespace Debug
{
    uint32_t Debugger::idCounter_ = 0;

    Debugger::Debugger(std::shared_ptr<MessageBus::MessageBus> bus)
        :MessageBus::MessageBusObserver(bus),
        id_(idCounter_)
    {
        ++idCounter_;
    }

    Debugger::~Debugger()
    {
        stop();
    }

    void Debugger::start()
    {
        bus_->attach(this);
    }

    void Debugger::stop()
    {
        bus_->detach(this);
    }

    void Debugger::update()
    {
        std::lock_guard<std::mutex> lock(idLock_);
        MessageBus::Message message = bus_->messages().back();
        printf("Debugger %d received: %s\n", id_, message.text().c_str());
        std::string id = std::to_string(id_);
        if (id == message.text())
        {
            id_ = -1;
        }
    }

    void Debugger::wait()
    {
        std::lock_guard<std::mutex> lock(idLock_);
        using namespace std::chrono_literals;

        std::this_thread::sleep_for(5000ms);

        printf("Debugger %d finished waiting\n", id_);
    }

}