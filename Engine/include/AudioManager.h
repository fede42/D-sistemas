#ifndef _AUDIO_MANAGER_H
#define _AUDIO_MANAGER_H

#include <iostream>
class AudioManager
{
private:
	AudioManager();
	static AudioManager *instance;
public:
	static AudioManager* getInstance();
	void startUp();
	void update();
	void shutDown();
};
#endif // !_AUDIO_MANAGER_H
