#include "Manager.h"

Manager* Manager::instance = nullptr;


Manager::Manager() {}

Manager * Manager::getInstance() {
	if (instance == nullptr) instance = new Manager();
	return instance;
}

void Manager::addForUpdate() {
}

void Manager::dispatcher() { //Queue Manager
	/*
	while (!exit) {
		if (!queue.empty()) {
			ThreadPool *pooledThread = new ThreadPool::create();
			if (!pooledThread) {
				SLEEP(15);
				continue;
			}
			//setThreadUpdate(pooledThread, queue.front());
			queue.pop();
		}//cola vacia
	}
	SLEEP(15); //*/
}

void Manager::joinAll() {
	//*
	for (int i = 0; i < threadPool._pool.size(); ++i){
		threadPool._pool.at(i)->join();
	} //*/
}
