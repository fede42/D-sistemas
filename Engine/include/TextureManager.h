#ifndef _TEXTURE_MANAGER_H
#define _TEXTURE_MANAGER_H

#include <iostream>
class TextureManager
{
private:
	TextureManager();
	static TextureManager *instance;
public:
	static TextureManager* getInstance();
	void startUp();
	void shutDown();
};
#endif // !_TEXTURE_MANAGER_H
