#include "DispatchQueue.h"

Threading::DispatchQueue::DispatchQueue()
{
}

Threading::DispatchQueue::~DispatchQueue()
{
}

void Threading::DispatchQueue::execute(MessageBus::MessageBusObserver& observer, MessageBus::Message const& message)
{
    if (!queue_.empty())
    {
        Task<MessageBus::MessageBusObserver> task = queue_.front();
        queue_.pop();
        task(observer, message);
    }
}

void Threading::DispatchQueue::push(Task<MessageBus::MessageBusObserver> task)
{
    queue_.push(task);
}

void Threading::DispatchQueue::pop()
{
    queue_.pop();
}
