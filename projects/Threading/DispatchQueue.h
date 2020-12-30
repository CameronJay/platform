#pragma once

#include <condition_variable>
#include <queue>
#include <mutex>
#include <MessageBus/Message.h>
#include <MessageBus/MessageBusObserver.h>
#include "Task.h"

namespace Threading
{
    class DispatchQueue
    {
        public:
            DispatchQueue(std::string const& name, size_t threadCount = 1);
            ~DispatchQueue();
            void push(Task task);
            void pop();

        protected:
            void start();
            void stop();
            void execute();

            std::queue<Task> queue_;
            std::mutex queueLock_;
            std::vector<std::thread> threads_;
            std::string const name_;
    };
}