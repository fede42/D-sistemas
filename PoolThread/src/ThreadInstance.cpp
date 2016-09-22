#include "threadInstance.h"

ThreadInstance::ThreadInstance()
	//: alive_(false)
{}

void ThreadInstance::init()
{
	alive_ = true;
}

bool ThreadInstance::update()
{
	if (!inUse())
		return false;
	std::cout << "updating... ";// << "\n";
	//SLEEP(50);
	alive_ = false;
	return alive_ == false;
}

bool ThreadInstance::inUse() const
{
	return alive_ > false;
}

ThreadInstance * ThreadInstance::getNext() const
{
	return state_.next;
}

void ThreadInstance::setNext(ThreadInstance* next)
{
	state_.next = next;
}
