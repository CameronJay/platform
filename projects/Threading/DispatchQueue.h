#pragma once

#include <queue>
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

            void execute(MessageBus::MessageBusObserver& observer, MessageBus::Message const& message);
            void push(Task<MessageBus::MessageBusObserver> task);
            void pop();

        protected:
            std::queue<Task<MessageBus::MessageBusObserver> > queue_;
    };
}