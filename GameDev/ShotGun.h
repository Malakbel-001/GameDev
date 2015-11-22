#pragma once
#include "Weapon.h"

class EntityFactory;
class ShotGun :
	public Weapon
{
public:
	ShotGun(Actor* ent);
	~ShotGun();
	virtual void Shoot(EntityFactory* eF);
};

