#include "MessageBus.h"
#include "MessageBusObserver.h"
#include <Threading/ThreadPool.h>
#include <Threading/Task.h>

namespace MessageBus
{
    MessageBus::MessageBus()
        :threadPool_(new Threading::ThreadPool("Bus", 1))
    {
        threadPool_->start();
    }

    MessageBus::~MessageBus()
    {
        threadPool_->stop();
    }

    void MessageBus::attach(MessageBusObserver* observer)
    {
        std::lock_guard<std::mutex> lock(observerLock_);
        observers_.push_back(observer);
    }

    void MessageBus::detach(MessageBusObserver* observer)
    {
        std::lock_guard<std::mutex> lock(observerLock_);
        observers_.remove(observer);
    }

    void MessageBus::receive(Message const& message)
    {
        messages_.push_back(message);
        Task task = std::bind(&MessageBus::notify, this);
        threadPool_->submit(task);
    }

    void MessageBus::notify()
    {
        std::lock_guard<std::mutex> lock(observerLock_);
        ObserverList::iterator iterator = observers_.begin();
        ObserverList::iterator end = observers_.end();

        for (iterator; iterator != end; ++iterator)
        {
            (*iterator)->update();
        }
    }
}