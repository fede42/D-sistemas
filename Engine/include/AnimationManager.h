#ifndef _ANIMATION_MANAGER_H
#define _ANIMATION_MANAGER_H

#include <iostream>
class AnimationManager
{
private:
	AnimationManager();
	static AnimationManager *instance;
public:
	static AnimationManager* getInstance();
	void startUp();
	void update();
	void shutDown();
};
#endif // !_ANIMATION_MANAGER_H
