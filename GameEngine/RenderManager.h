#pragma once
#include <iostream>
class RenderManager
{
private:
	RenderManager();
	static RenderManager *instance;
public:
	static RenderManager* getInstance();
	void startUp();
	void update();
	void shutDown();
};