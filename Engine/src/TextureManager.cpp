#include "stdafx.h"
#include "TextureManager.h"


TextureManager::TextureManager()
{
}

TextureManager* TextureManager::instance = nullptr;

TextureManager * TextureManager::getInstance()
{
	if (instance == nullptr) instance = new TextureManager();
	return instance;
}

void TextureManager::startUp()
{
	std::cout << "TextureManager started" << '\n';
}

void TextureManager::shutDown()
{
	std::cout << "TextureManager shutted down" << '\n';
}
