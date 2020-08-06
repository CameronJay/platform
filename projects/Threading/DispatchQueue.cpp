#include "DispatchQueue.h"

Threading::DispatchQueue::DispatchQueue(std::string const& name, size_t threadCount)
    :run_(true),
    name_(name),
    threads_(threadCount)
{
    start();
}

Threading::DispatchQueue::~DispatchQueue()
{
    stop();
}

void Threading::DispatchQueue::start()
{
    for (size_t i = 0; i < threads_.size(); i++)
    {
        threads_[i] = std::thread(&DispatchQueue::execute, this);
    }
}

void Threading::DispatchQueue::stop()
{
    {
        std::lock_guard<std::mutex> lock(queueLock_);
        run_ = false;
    }
    cv_.notify_all();

    for (size_t i = 0; i < threads_.size(); i++)
    {
        if (threads_[i].joinable())
        {
            threads_[i].join();
        }
    }
}

void Threading::DispatchQueue::execute()
{
    std::unique_lock<std::mutex> lock(queueLock_);

    do {
        //Wait until we have data or a quit signal
        cv_.wait(lock, [this] { return (queue_.size() || !run_); });

        if (run_ && (queue_.size()))
        {
            Task task = queue_.front();
            queue_.pop();

            lock.unlock();

            task();

            lock.lock();
        }
    } while (run_);
}

void Threading::DispatchQueue::push(Task task)
{
    {
        std::lock_guard<std::mutex> lock(queueLock_);
        queue_.push(task);
    }
    cv_.notify_one();
}

void Threading::DispatchQueue::pop()
{
    std::lock_guard<std::mutex> lock(queueLock_);
    queue_.pop();
}
