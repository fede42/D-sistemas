#include "stdafx.h"
#include "RenderManager.h"


RenderManager::RenderManager()
{
}

RenderManager* RenderManager::instance = nullptr;

RenderManager * RenderManager::getInstance()
{
	if (instance == nullptr) instance = new RenderManager();
	return instance;
}

void RenderManager::startUp()
{
	std::cout << "RenderManager started" << '\n';
}

void RenderManager::update()
{
	std::cout << "Updating RenderManager..." << '\n';
}

void RenderManager::shutDown()
{
	std::cout << "RenderManager shutted down" << '\n';
}
