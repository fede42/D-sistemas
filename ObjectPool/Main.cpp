// ObjectPool.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <assert.h>
#include <time.h>
#include <string>

#define POOLSIZE 100
int count = 0;

class Particle
{
public:
	Particle()
		: framesLeft_(0)
	{}
	void init(double x, double y,
		double xVel, double yVel, int lifetime)
	{
		state_.live.x_ = x;
		state_.live.y_ = y;
		state_.live.xVel_ = xVel;
		state_.live.yVel_ = yVel;
		framesLeft_ = lifetime;
	}
	bool animate()
	{   
		if (!inUse()) 
			return false;
		framesLeft_--;
		state_.live.x_ += state_.live.xVel_;
		state_.live.y_ += state_.live.yVel_;
		count++;
		std::cout << count << '\n';
		return framesLeft_ == 0;
	}

	bool inUse() const 
	{ 
		return framesLeft_ > 0; 
	}
	
	Particle* getNext() const { return state_.next; }
	
	void setNext(Particle* next) { state_.next = next; }

private:
	int framesLeft_;

	union
	{
		// State when it's in use.
		struct
		{
			double x_, y_;
			double xVel_, yVel_;
		} live;
		// State when it's available.
		Particle* next;
	} state_;
};

class ParticlePool
{
public:
	ParticlePool()
	{
		// The first one is available.
		firstAvailable_ = &particles_[0];
		// Each particle points to the next.
		for (int i = 0; i < POOL_SIZE - 1; i++)
		{
			particles_[i].setNext(&particles_[i + 1]);
		}
		// The last one terminates the list.
		particles_[POOL_SIZE - 1].setNext(NULL);
	}

	void create(double x, double y,
		double xVel, double yVel, int lifetime)
	{
		{
			// Make sure the pool isn't full.
			assert(firstAvailable_ != NULL);
			// Remove it from the available list.
			Particle* newParticle = firstAvailable_;
			firstAvailable_ = newParticle->getNext();
			newParticle->init(x, y, xVel, yVel, lifetime);
		}
	}

	void animate()
	{
		for (int i = 0; i < POOL_SIZE; i++)
		{
			if (particles_[i].animate())
			{
				// Add this particle to the front of the list.
				/*count++;
				std::cout << count << '\n';*/
				particles_[i].setNext(firstAvailable_);
				firstAvailable_ = &particles_[i];
				create(0,0,6,6,1);
			}
		}
	}
private:
	static const int POOL_SIZE = POOLSIZE;
	Particle particles_[POOL_SIZE];
	Particle* firstAvailable_;
};

class ParticlePoolDinamic
{
public:
	ParticlePoolDinamic(double _x, double _y,
		double _xVel, double _yVel, int _lifetime) {
		this->x = _x;
		this->y = _y;
		this->xVel = _xVel;
		this->yVel = _yVel;
		this->lifetime = _lifetime;

		for (int i = 0; i < POOL_SIZE; i++)
		{
			particles_[i] = NULL;
		}
	}

	void create()
	{
		for (int i = 0; i < POOL_SIZE; i++)
		{
			if (particles_[i] == NULL) {
				particles_[i] = new Particle();
				particles_[i]->init(x, y, xVel, yVel, lifetime);
				return;
			}
		}			
	}

	void animate()
	{
		for (int i = 0; i < POOL_SIZE; i++)
		{
			if (particles_[i]->animate())
			{
				delete particles_[i];
				particles_[i] = NULL;
				create();
			}
		}
	}
private:
	double x, y;
	double xVel, yVel; 
	int lifetime;
	static const int POOL_SIZE = POOLSIZE;
	Particle* particles_[POOL_SIZE];
};

int main()
{
	clock_t start1, start2;
	double duration;
	ParticlePool prueba1;
	ParticlePoolDinamic prueba2(0,0,6,6,6);

	//Prueba pool 
	for (int i = 0; i < POOLSIZE; i++) {
		prueba1.create(0, 0, 6, 6, 1);
	}
	start1 = clock();		
	for (int i = 0; i < 250000; i++) {
		prueba1.animate();
	}
	duration = (clock() - start1) / (double)CLOCKS_PER_SEC;
	std::cout << "Tiempo: " << duration << '\n';

	//Prueba pool dinámico
	for (int i = 0; i < POOLSIZE; i++) {
		prueba2.create();
	}
	start2 = clock();
	for (int i = 0; i < 250000; i++) {
		prueba2.animate();
	}
	duration = (clock() - start2) / (double)CLOCKS_PER_SEC;
	std::cout << "Tiempo: " << duration << '\n';

	std::cin.get();
    return 0;
}