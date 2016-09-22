#ifndef _THREADINSTANCE_H
#define _THREADINSTANCE_H
#include <iostream>
#include "Sleep.h"
#include "Threadable.h"
#include <string>

class ThreadInstance : Threadable
{
public:
	ThreadInstance();

	void init();
	bool update();
	bool inUse() const;
	ThreadInstance* getNext() const;
	void setNext(ThreadInstance* next);

private:
	bool alive_;

	union
	{
		// State when it's in use.
		struct
		{

		} live;
		// State when it's available.
		ThreadInstance* next;
	} state_;
};
#endif // !_THREADINSTANCE_H
