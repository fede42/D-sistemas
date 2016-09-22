#include "stdafx.h"
#include "VideoManager.h"

VideoManager::VideoManager()
{
}

VideoManager* VideoManager::instance = nullptr;

VideoManager * VideoManager::getInstance()
{
	if (instance == nullptr) instance = new VideoManager();
	return instance;
}

void VideoManager::startUp()
{
	std::cout << "VideoManager started" << '\n';
}

void VideoManager::shutDown()
{
	std::cout << "VideoManager shutted down" << '\n';
}
