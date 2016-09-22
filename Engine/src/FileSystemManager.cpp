#include "stdafx.h"
#include "FileSystemManager.h"

FileSystemManager::FileSystemManager()
{
}

FileSystemManager* FileSystemManager::instance = nullptr;

FileSystemManager * FileSystemManager::getInstance()
{
	if (instance == nullptr) instance = new FileSystemManager();
	return instance;
}

void FileSystemManager::startUp()
{
	std::cout << "FileSystemManager started" << '\n';
}

void FileSystemManager::shutDown()
{
	std::cout << "FileSystemManager shutted down" << '\n';
}
