#ifndef _SINGLETON
#define _SINGLETON

class Singleton {
private:
	Singleton();
	static Singleton *instance;
	int a, b;
public:
	static Singleton* getInstance();
	void set(int a, int b);
	int getSum();
};

#endif // !_SINGLETON
