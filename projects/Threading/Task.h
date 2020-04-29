#pragma once

#include <MessageBus/Message.h>
#include <functional>

template <class T>
using Task = std::function<void(T&, MessageBus::Message const&)>;