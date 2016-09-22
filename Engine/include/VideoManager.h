#ifndef _VIDEO_MANAGER_H
#define _VIDEO_MANAGER_H

#include <iostream>
class VideoManager
{
private:
	VideoManager();
	static VideoManager *instance;
public:
	static VideoManager* getInstance();
	void startUp();
	void shutDown();
};
#endif // !_VIDEO_MANAGER_H
