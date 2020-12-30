#include "DispatchQueue.h"

Threading::DispatchQueue::DispatchQueue(std::string const& name, size_t threadCount)
    :name_(name),
    threads_(threadCount)
{
}

Threading::DispatchQueue::~DispatchQueue()
{
}

void Threading::DispatchQueue::start()
{
}

void Threading::DispatchQueue::stop()
{
}

void Threading::DispatchQueue::execute()
{
}

void Threading::DispatchQueue::push(Task task)
{
}

void Threading::DispatchQueue::pop()
{
}
