#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <vector>
#include <thread>
#include <assert.h>
#include <string>
#include "ThreadInstance.h"
#define POOLSIZE 100

class ThreadPool {
public:
	int count;
	std::vector < std::thread*> _pool;
	ThreadPool();
	void create();
	void update();

private:
	static const int POOL_SIZE = POOLSIZE;
	ThreadInstance threads_[POOL_SIZE];
	ThreadInstance* firstAvailable_;
};
#endif // ! _THREADPOOL_H