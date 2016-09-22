#include "stdafx.h"
#include "Singleton.h"

Singleton::Singleton()
{
}

Singleton* Singleton::instance = nullptr;

Singleton * Singleton::getInstance()
{
	if (instance == nullptr) instance = new Singleton();
	return instance;
}

void Singleton::set(int _a, int _b)
{
	this->a = _a;
	this->b = _b;
}

int Singleton::getSum()
{
	return a + b;
}
