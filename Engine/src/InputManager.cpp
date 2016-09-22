#include "stdafx.h"
#include "InputManager.h"

InputManager::InputManager(){}

InputManager* InputManager::instance = nullptr;


InputManager * InputManager::getInstance(){
	if (instance == nullptr) instance = new InputManager();
	return instance;
}

void InputManager::startUp(){
	std::thread t(&InputManager::update, this);
	std::cout << "RenderManager started" << '\n';	
	t.detach();
	wasConnected = true;
}

void InputManager::update()
{
	while (1) {
		//Sleep(100);
		std::cout << "Updating InputManager..." << '\n';

		if (!gamepad.Refresh()) {
			if (wasConnected) {
				wasConnected = false;

				std::cout << "Please connect an Xbox 360 controller." << '\n';
			}
		}
		else {
			if (!wasConnected) {
				wasConnected = true;

				std::cout << "Controller connected on port " << gamepad.GetPort() << '\n';
			}

			// Analog Sticks
			std::cout << "Left thumb stick: (" << gamepad.leftStickX << ", " << gamepad.leftStickY << ")   Right thumb stick : (" << gamepad.rightStickX << ", " << gamepad.rightStickY << ")" << '\n';
			// Analog thumb sticks (when pressed in and used as a button)
			if (gamepad.IsPressed(XINPUT_GAMEPAD_LEFT_THUMB)) std::cout << "(Left Thumb) button pressed" << '\n';
			if (gamepad.IsPressed(XINPUT_GAMEPAD_RIGHT_THUMB)) std::cout << "(Right Thumb) button pressed" << '\n';

			// Analog Triggers
			std::cout << "Left analog trigger: " << gamepad.leftTrigger << "   Right analog trigger: " << gamepad.rightTrigger << '\n';
			// Shoulder buttons
			if (gamepad.IsPressed(XINPUT_GAMEPAD_LEFT_SHOULDER)) std::cout << "(LB) button pressed" << '\n';
			if (gamepad.IsPressed(XINPUT_GAMEPAD_RIGHT_SHOULDER)) std::cout << "(RB) button pressed" << '\n';

			// Face buttons
			if (gamepad.IsPressed(XINPUT_GAMEPAD_A)) std::cout << "(A) button pressed" << '\n';
			if (gamepad.IsPressed(XINPUT_GAMEPAD_B)) std::cout << "(B) button pressed" << '\n';
			if (gamepad.IsPressed(XINPUT_GAMEPAD_X)) std::cout << "(X) button pressed" << '\n';
			if (gamepad.IsPressed(XINPUT_GAMEPAD_Y)) std::cout << "(Y) button pressed" << '\n';

			// Directional pad arrows
			if (gamepad.IsPressed(XINPUT_GAMEPAD_DPAD_UP)) std::cout << "(Up) button pressed" << '\n';
			if (gamepad.IsPressed(XINPUT_GAMEPAD_DPAD_DOWN)) std::cout << "(Down) button pressed" << '\n';
			if (gamepad.IsPressed(XINPUT_GAMEPAD_DPAD_LEFT)) std::cout << "(Left) button pressed" << '\n';
			if (gamepad.IsPressed(XINPUT_GAMEPAD_DPAD_RIGHT)) std::cout << "(Right) button pressed" << '\n';

			//Centre buttons
			if (gamepad.IsPressed(XINPUT_GAMEPAD_BACK)) std::cout << "(Back) button pressed" << '\n';
			if (gamepad.IsPressed(XINPUT_GAMEPAD_START)) std::cout << "(Start) button pressed" << '\n';
		}
	}
}

void InputManager::shutDown(){
	std::cout << "RenderManager shutted down" << '\n';
}
