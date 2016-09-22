#include "stdafx.h"
#include "MemoryManager.h"


MemoryManager::MemoryManager()
{
}

MemoryManager* MemoryManager::instance = nullptr;

MemoryManager * MemoryManager::getInstance()
{
	if (instance == nullptr) instance = new MemoryManager();
	return instance;
}

void MemoryManager::startUp()
{
	std::cout << "MemoryManager started" << '\n';
}

void MemoryManager::shutDown()
{
	std::cout << "MemoryManager shutted down" << '\n';
}
