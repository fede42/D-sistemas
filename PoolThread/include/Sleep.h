#ifndef _SLEEP_H
#define _SLEEP_H

#include <thread>
#include <chrono>
#define SLEEP(MILLIS) std::this_thread::sleep_for(std::chrono::milliseconds(MILLIS))

#endif // !_SLEEP_H