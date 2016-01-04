#pragma once
#include "Player.h"
class Vehicle :
	public Player
{
public:
	Vehicle();
	~Vehicle();

	void SetPassenger(Object* _passenger);
	Object* GetPassenger();


private:
	Object* passenger;
};

