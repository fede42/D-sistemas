#ifndef _GAMEPAD_H
#define _GAMEPAD_H

#include <iostream>
#include <windows.h>
#include <xinput.h>

class Gamepad
{
private:
	int cId;
	XINPUT_STATE state;

	float deadzoneX;
	float deadzoneY;

public:
	Gamepad() : deadzoneX(0.05f), deadzoneY(0.02f) {}
	Gamepad(float dzX, float dzY) : deadzoneX(dzX), deadzoneY(dzY) {}

	float leftStickX;
	float leftStickY;
	float rightStickX;
	float rightStickY;
	float leftTrigger;
	float rightTrigger;

	int  GetPort();
	XINPUT_GAMEPAD *GetState();
	bool CheckConnection();
	bool Refresh();
	bool IsPressed(WORD);
};

#endif // !_GAMEPAD_H