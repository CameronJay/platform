#include "MessageBus.h"
#include "MessageBusObserver.h"
#include <Threading/DispatchQueue.h>
#include <Threading/Task.h>

namespace MessageBus
{
    MessageBus::MessageBus(Threading::DispatchQueue* dispatchQueue)
        :dispatchQueue_(dispatchQueue)
    {
    }

    MessageBus::~MessageBus()
    {
    }

    void MessageBus::attach(MessageBusObserver* observer)
    {
        observers_.push_back(observer);
    }

    void MessageBus::detach(MessageBusObserver* observer)
    {
        observers_.remove(observer);
    }

    void MessageBus::receive(Message const& message)
    {
        messages_.push_back(message);
        Task task = std::bind(&MessageBus::notify, this);
        dispatchQueue_->push(task);
    }

    void MessageBus::notify()
    {
        ObserverList::iterator iterator = observers_.begin();
        ObserverList::iterator end = observers_.end();

        for (iterator; iterator != end; ++iterator)
        {
            (*iterator)->update();
        }
    }
}