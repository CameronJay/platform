#pragma once

#include <MessageBus/Message.h>
#include <queue>
#include <functional>


using Task = std::function<void(void)>;
typedef std::queue<Task> TaskQueue;