#pragma once

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
            DispatchQueue();
            ~DispatchQueue();

            void start();
            void execute();
            void push(Task task);
            void pop();

        protected:
            std::queue<Task> queue_;
            std::mutex queueLock_;
    };
}