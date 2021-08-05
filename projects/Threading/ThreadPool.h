#pragma once

#include <mutex>
#include <queue>
#include <vector>
#include <thread>
#include "Task.h"

namespace Threading
{
    class Semaphore;

    class ThreadPool
    {
    public:
        ThreadPool(std::string const name, size_t const threadCount = 1);
        ~ThreadPool();
        virtual void start();
        virtual void stop();
        virtual void submit(Task task);

    protected:
        void pool();

    private:
        std::queue<Task> taskQueue_;
        std::queue<Task> completedTasks_;
        std::vector<std::thread*> threads_;
        std::mutex taskLock_;
        std::mutex threadsLock_;
        std::shared_ptr<Semaphore> poolSignals_;

        std::string const name_;
        size_t const threadCount_;
        bool running_;
    };
}