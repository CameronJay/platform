#include "TaskQueue.h"

Threading::TaskQueue::TaskQueue()
{
}

Threading::TaskQueue::~TaskQueue()
{
}

void Threading::TaskQueue::start()
{
}

void Threading::TaskQueue::execute()
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

void Threading::TaskQueue::push(Task task)
{
    queueLock_.lock();
    queue_.push(task);
    queueLock_.unlock();
}

void Threading::TaskQueue::pop()
{
    queueLock_.lock();
    queue_.pop();
    queueLock_.unlock();
}
