#ifndef _ASSET_H
#define _ASSET_H

#include "Threadable.h"
#include "Sleep.h"
#include <iostream>
#include <string>

class Asset : Threadable {
public:
	std::string _name;

	void setName(const int& i) {
		_name = std::to_string(i);
	}

	bool update() {
		while (1) {
			std::cout << "updating " << _name << "\n";
			SLEEP(20);
		}
		return true;
	}
};

#endif // !_ASSET_H
