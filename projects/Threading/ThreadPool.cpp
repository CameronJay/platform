#include "ThreadPool.h"
#include "Semaphore.h"

namespace Threading
{

    ThreadPool::ThreadPool(std::string const& name, size_t const threadCount)
        :name_(name),
        threadCount_(threadCount),
        running_(false),
        poolSignals_(new Semaphore(0, threadCount)) // start empty and only post when we submit a task
    {
        poolSignals_->init();
    }

    ThreadPool::~ThreadPool()
    {
        stop();
    }

    void ThreadPool::start()
    {
        running_ = true;
        std::lock_guard<std::mutex> lock(threadsLock_);
        for (size_t i = 0; i < threadCount_; ++i)
        {
            threads_.push_back(new std::thread(&ThreadPool::pool, this));
        }
    }

    void ThreadPool::stop()
    {
        running_ = false;
        poolSignals_->post(threadCount_); // post semaphore till all threads can finish

        std::lock_guard<std::mutex> lock(threadsLock_);
        for (size_t i = 0; i < threads_.size(); ++i)
        {
            if (threads_[i]->joinable())
            {
                threads_[i]->join();
            }
        }

        poolSignals_->destroy();
    }

    void ThreadPool::pool()
    {
        while (running_)
        {
            poolSignals_->wait();

            if (running_) // signal wasn't posted to quit
            {
                Task task;
                {
                    std::lock_guard<std::mutex> lock(taskLock_);
                    if (taskQueue_.size() > 0)
                    {
                        task = taskQueue_.front();
                        taskQueue_.pop();
                        completedTasks_.push(task);
                    }
                }
                task(); // empty function if not pulled from task queue
            }
        }
    }

    void ThreadPool::submit(Task task)
    {
        {
            std::lock_guard<std::mutex> lock(taskLock_);
            taskQueue_.push(task);
        }
        poolSignals_->post();
    }

}