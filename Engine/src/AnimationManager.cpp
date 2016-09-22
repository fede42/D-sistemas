#include "stdafx.h"
#include "AnimationManager.h"

AnimationManager::AnimationManager()
{
}

AnimationManager* AnimationManager::instance = nullptr;

AnimationManager * AnimationManager::getInstance()
{
	if (instance == nullptr) instance = new AnimationManager();
	return instance;
}

void AnimationManager::startUp()
{
	std::cout << "AnimationManager started" << '\n';
}

void AnimationManager::update()
{
	std::cout << "Updating AnimationManager..." << '\n';
}

void AnimationManager::shutDown()
{
	std::cout << "AnimationManager shutted down" << '\n';
}
