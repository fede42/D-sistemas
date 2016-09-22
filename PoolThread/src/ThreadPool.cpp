#include "ThreadPool.h"

ThreadPool::ThreadPool()
{
	count = 0;
	firstAvailable_ = &threads_[0];
	
	for (int i = 0; i < POOL_SIZE - 1; i++)
	{
		threads_[i].setNext(&threads_[i + 1]);
	}
	
	threads_[POOL_SIZE - 1].setNext(NULL);
}

void ThreadPool::create()
{	
	assert(firstAvailable_ != NULL);

	ThreadInstance* newThread = firstAvailable_;
	firstAvailable_ = newThread->getNext();
	newThread->init();
}

void ThreadPool::update()
{
	count++;
	std::cout << count;

	for (int i = 0; i < POOL_SIZE; i++)
	{
		if (threads_[i].update())
		{
			threads_[i].setNext(firstAvailable_);
			firstAvailable_ = &threads_[i];
		}
	}
}
