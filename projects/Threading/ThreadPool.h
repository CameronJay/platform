#pragma once

#include <queue>
#include <mutex>
#include <MessageBus/Message.h>
#include <MessageBus/MessageBusObserver.h>
#include "Task.h"

namespace Threading
{
    class ThreadPool
    {
        public:
            ThreadPool(std::string const& name, size_t threadCount = 1);
            ~ThreadPool();
            void push(Task task);
            void pop();

        protected:
            void start();
            void stop();
            void execute();

            TaskQueue taskQueue_;
            TaskQueue completedTasks_;
            std::mutex queueLock_;
            std::vector<std::thread> threads_;
            std::string const name_;
    };
}