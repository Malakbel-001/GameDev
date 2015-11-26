#pragma once
#include "Player.h"

class EntityFactory;
class Weapon
{		
public:
	Weapon(Actor* _actor);
	~Weapon();
	virtual void Shoot(EntityFactory* eF);
	virtual void AddAmmo(int ammo);

protected:
	Actor* actor;
	int ammo;
	float fireSpeed;
	float timecounter;
	b2Vec2 vec;
	int maxAmmo;
	
	
	
};

