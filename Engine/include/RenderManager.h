#ifndef _RENDER_MANAGER_H
#define _RENDER_MANAGER_H

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
#endif // !_RENDER_MANAGER_H