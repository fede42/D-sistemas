#ifndef _INPUT_MANAGER_H
#define _INPUT_MANAGER_H

#include "Gamepad.h"
#include <thread>

class InputManager{
private:
	InputManager();
	static InputManager *instance;
	Gamepad gamepad;
	bool wasConnected;

public:
	static InputManager* getInstance();
	void startUp();
	void update();
	void shutDown();
};


#endif // !_INPUT_MANAGER_H
