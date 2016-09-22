#include "stdafx.h"
#include "PhysicsManager.h"


PhysicsManager::PhysicsManager()
{
}

PhysicsManager* PhysicsManager::instance = nullptr;

PhysicsManager * PhysicsManager::getInstance()
{
	if (instance == nullptr) instance = new PhysicsManager();
	return instance;
}

void PhysicsManager::startUp()
{
	std::cout << "PhysicsManager started" << '\n';
}

void PhysicsManager::update()
{
	std::cout << "Updating PhysicsManager..." << '\n';
}

void PhysicsManager::shutDown()
{
	std::cout << "PhysicsManager shutted down" << '\n';
}