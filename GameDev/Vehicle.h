#pragma once
#include "Player.h"
class Vehicle :
	public Player
{
public:
	Vehicle();
	~Vehicle();


private:
	Object* passenger;
};

