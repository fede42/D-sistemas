#include <iostream>
#include <thread>
#include <chrono>

void func1(void) {
	int x = 10;
	while (x--) {
		std::cout << "soy func1\n";
	}
}

void func2(void) {
	int x = 10;
	while (x--) {
		std::cout << "soy func2\n";
	}
}

void main(void) {
	std::thread f1(func1);
	std::thread f2(func2);
	std::cout << "lanzados los 2\n";
	f1.join();
	f2.join();
	std::cout << "finalizado\n";
	std::cout << "\n";
}