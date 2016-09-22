// GameEngine.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include "RenderManager.h"
#include "PhysicsManager.h"
#include "AnimationManager.h"
#include "TextureManager.h"
#include "VideoManager.h"
#include "AudioManager.h"
#include "MemoryManager.h"
#include "FileSystemManager.h"

RenderManager *gRenderManager;
PhysicsManager gPhysicsManager;
AnimationManager gAnimationManager;
TextureManager gTextureManager;
VideoManager gVideoManager;
AudioManager gAudioManager;
MemoryManager gMemoryManager;
FileSystemManager gFileSystemManager;

int main()
{
	gRenderManager = RenderManager::getInstance();

	gRenderManager->startUp();
	gPhysicsManager.startUp();
	gAnimationManager.startUp();
	gTextureManager.startUp();
	gVideoManager.startUp();
	gAudioManager.startUp();
	gMemoryManager.startUp();
	gFileSystemManager.startUp();

	while (!exit) { //main loop
		gRenderManager->update();
	}

	gFileSystemManager.shutDown();
	gMemoryManager.shutDown();
	gAudioManager.shutDown();
	gVideoManager.shutDown();
	gTextureManager.shutDown();
	gAnimationManager.shutDown();
	gPhysicsManager.shutDown();
	gRenderManager->shutDown();

	std::cin.get();
    return 0;
}

