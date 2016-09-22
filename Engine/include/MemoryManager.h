#ifndef _MEMORY_MANAGER_H
#define _MEMORY_MANAGER_H

#include <iostream>
class MemoryManager
{
private:
	MemoryManager();
	static MemoryManager *instance;
public:
	static MemoryManager* getInstance();
	void startUp();
	void shutDown();
};
#endif // !_MEMORY_MANAGER_H
