#include "stdafx.h"
#include "AudioManager.h"


AudioManager::AudioManager()
{
}

AudioManager* AudioManager::instance = nullptr;

AudioManager * AudioManager::getInstance()
{
	if (instance == nullptr) instance = new AudioManager();
	return instance;
}

void AudioManager::startUp()
{
	std::cout << "AudioManager started" << '\n';
}

void AudioManager::update()
{
	std::cout << "Updating AudioManager..." << '\n';
}

void AudioManager::shutDown()
{
	std::cout << "AudioManager shutted down" << '\n';
}
