#include "DispatchQueue.h"

Threading::DispatchQueue::DispatchQueue()
{
}

Threading::DispatchQueue::~DispatchQueue()
{
}

void Threading::DispatchQueue::start()
{
}

void Threading::DispatchQueue::execute()
{
    queueLock_.lock();
    if (!queue_.empty())
    {
        Task task = queue_.front();
        queue_.pop();
        task();
    }
    queueLock_.unlock();
}

void Threading::DispatchQueue::push(Task task)
{
    queueLock_.lock();
    queue_.push(task);
    queueLock_.unlock();
}

void Threading::DispatchQueue::pop()
{
    queueLock_.lock();
    queue_.pop();
    queueLock_.unlock();
}
