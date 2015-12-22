#pragma once
#include "Weapon.h"
class Cannon :
	public Weapon
{
public:
	Cannon();
	~Cannon();
	virtual void Shoot(EntityFactory* eF);

	Weapon* EmptyClone();
};

