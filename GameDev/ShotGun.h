#pragma once
#include "Weapon.h"

class EntityFactory;
class ShotGun :
	public Weapon
{
public:
	ShotGun();
	~ShotGun();
	virtual void Shoot(EntityFactory* eF);

	Weapon* EmptyClone();

};
