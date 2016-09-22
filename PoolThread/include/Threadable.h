#pragma once

class Threadable {
public:
	virtual void init() {}
	virtual bool update() { return false; }
	Threadable() {
		init();
	}
};