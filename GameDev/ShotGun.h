#pragma once
#include "Weapon.h"

class EntityFactory;
class ShotGun :
	public Weapon
{
public:
	ShotGun();
	~ShotGun();
	virtual bool Shoot(EntityFactory* eF, float accumulatedDt);

	Weapon* EmptyClone();

};
