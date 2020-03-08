#include "MessageBus.h"
#include "MessageBusObserver.h"

namespace MessageBus
{
    MessageBus::MessageBus()
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
        notify(messages_.back());
    }

    void MessageBus::notify(Message const& message)
    {
        ObserverList::iterator iterator = observers_.begin();
        ObserverList::iterator end = observers_.end();

        for (iterator; iterator != end; ++iterator)
        {
            (*iterator)->update(message);
        }
    }
}