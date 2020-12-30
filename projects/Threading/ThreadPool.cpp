#include "ThreadPool.h"

Threading::ThreadPool::ThreadPool(std::string const& name, size_t threadCount)
    :name_(name),
    threads_(threadCount)
{
}

Threading::ThreadPool::~ThreadPool()
{
}

void Threading::ThreadPool::start()
{
}

void Threading::ThreadPool::stop()
{
}

void Threading::ThreadPool::execute()
{
}

void Threading::ThreadPool::push(Task task)
{
}

void Threading::ThreadPool::pop()
{
}
