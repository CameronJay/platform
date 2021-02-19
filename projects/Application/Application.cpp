#include "Application.h"
#include <cstdio>
#include <chrono> // std::chrono::microseconds
#include <thread> // std::this_thread::sleep_for
#include <Debugger/Debugger.h>
#include <Input/InputReader.h>
#include <MessageBus/MessageBus.h>
#include <Threading/ThreadPool.h>

namespace App
{
    const std::string Application::name_ = "Main";

    Application::Application()
        :pool_(new Threading::ThreadPool(name_, 2)),
        bus_(new MessageBus::MessageBus()),
        debugger_(new Debug::Debugger(bus_)),
        inputReader_(new Input::InputReader(bus_))
    {
    }

    Application::~Application()
    {
    }

    void Application::start()
    {
        Task taskZero = std::bind(&Debug::Debugger::start, debugger_);
        pool_->submit(taskZero);
        pool_->start();
        inputReader_->start();
    }

}