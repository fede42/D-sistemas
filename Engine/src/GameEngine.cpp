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
#include "InputManager.h"
#include "Gamepad.h"

RenderManager *gRenderManager;
PhysicsManager *gPhysicsManager;
InputManager *gInputManager;
AnimationManager *gAnimationManager;
TextureManager *gTextureManager;
VideoManager *gVideoManager;
AudioManager *gAudioManager;
MemoryManager *gMemoryManager;
FileSystemManager *gFileSystemManager;

int main(){
	gRenderManager = RenderManager::getInstance();
	gPhysicsManager = PhysicsManager::getInstance();
	gInputManager = InputManager::getInstance();
	gAnimationManager = AnimationManager::getInstance();
	gTextureManager = TextureManager::getInstance();
	gVideoManager = VideoManager::getInstance();
	gAudioManager = AudioManager::getInstance();
	gMemoryManager = MemoryManager::getInstance();
	gFileSystemManager = FileSystemManager::getInstance();

	gRenderManager->startUp();
	gPhysicsManager->startUp();
	gInputManager->startUp();
	gAnimationManager->startUp();
	gTextureManager->startUp();
	gVideoManager->startUp();
	gAudioManager->startUp();
	gMemoryManager->startUp();
	gFileSystemManager->startUp();

	

	while (true) { //main loop
		gRenderManager->update();
		gPhysicsManager->update();
		/*gInputManager->update();*/
		gAnimationManager->update();
		gAnimationManager->update();

		if (GetAsyncKeyState(VK_ESCAPE)){
			std::cout << "You've pressed the escape key" << '\n';
			break;
		}
	}

	gFileSystemManager->shutDown();
	gMemoryManager->shutDown();
	gAudioManager->shutDown();
	gVideoManager->shutDown();
	gTextureManager->shutDown();
	gAnimationManager->shutDown();
	gInputManager->shutDown();
	gPhysicsManager->shutDown();
	gRenderManager->shutDown();

	std::cin.get();
    return 0;
}

