#ifndef _MANAGER_H
#define _MANAGER_H

#include "Sleep.h"
#include "ThreadPool.h"
#include "Asset.h"
#include <queue>

class Manager { //Singleton
private:
	Manager();
	static Manager *instance;

	std::queue <ThreadPool> queue;
	ThreadPool threadPool;
public:
	static Manager* getInstance();

	void addForUpdate();
	void dispatcher();
	void joinAll();
	//void setThreadUpdate(&Thread _thread, Asset _asset);
};

#endif // !_MANAGER_H
