#ifndef _FILESYSTEM_MANAGER_H
#define _FILESYSTEM_MANAGER_H

#include <iostream>
class FileSystemManager
{
private:
	FileSystemManager();
	static FileSystemManager *instance;
public:
	static FileSystemManager* getInstance();
	void startUp();
	void shutDown();
};
#endif // !_FILESYSTEM_MANAGER_H
