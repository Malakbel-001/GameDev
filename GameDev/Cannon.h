#pragma once
#include "Weapon.h"
class Cannon :
	public Weapon
{
public:
	Cannon();
	~Cannon();
	virtual bool Shoot(EntityFactory* eF, float accumulatedDt, float manipulatorSpeed);

	Weapon* EmptyClone();
};

