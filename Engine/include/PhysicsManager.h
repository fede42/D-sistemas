#ifndef _PHYSICS_MANAGER_H
#define _PHYSICS_MANAGER_H

#include <iostream>
class PhysicsManager
{
private:
	PhysicsManager();
	static PhysicsManager *instance;
public:
	static PhysicsManager* getInstance();
	void startUp();
	void update();
	void shutDown();
};
#endif // !_PHYSICS_MANAGER_H
