
#include "ThreadPool.h"
#include "Threadable.h"
#include "Sleep.h"
#include <iostream>
#include <string>

#define HOLA(M) SLEEP(M)

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

class EjemploInstanciaThread : Threadable {
public: 
	std::string _name;

	void setName(const int& i) {
		_name = std::to_string(i);
	}

	bool update() {
		while (1) {
			std::cout << "updating " << _name << "\n";
			HOLA(1000);
		}
		return false;
	}
};

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

ThreadPool threadPoolTest;
#define NUMTHREADS 5

void main(void) {
	/*for (int i = 0; i < NUMTHREADS; ++i) {
		EjemploInstanciaThread *e = new EjemploInstanciaThread();
		e->setName(i);
		std::thread *thread = new std::thread(&EjemploInstanciaThread::update, e);
		std::cout << "\n";
		threadPoolTest._pool.push_back(thread);
	}*/

	/*for (int i = 0; i < threadPoolTest._pool.size(); ++i) {
		threadPoolTest._pool.at(i)->join();
	}*/

	for (int i = 0; i < 100; i++) {
		threadPoolTest.create();
	}
	for (int i = 0; i < 1; i++) {
		threadPoolTest.update();
	}
}