#include "stdafx.h"
#include "AudioManager.h"


AudioManager::AudioManager()
{
}


AudioManager::~AudioManager()
{
}

void AudioManager::startUp()
{
	std::cout << "AudioManager started" << '\n';
}

void AudioManager::shutDown()
{
	std::cout << "AudioManager shutted down" << '\n';
}
