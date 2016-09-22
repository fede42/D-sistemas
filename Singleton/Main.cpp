#include "stdafx.h"
#include <iostream>
#include "Singleton.h"

Singleton *s1, *s2;

int main()
{
	s1 = Singleton::getInstance();
	s2 = Singleton::getInstance();
	s1->set(332, 88);
	std::cout << s1->getSum() << '\n';
	std::cout << s2->getSum() << '\n';
	std::cin.get();
	return 0;
}

