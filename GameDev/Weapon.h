#pragma once
#include "Player.h"
#include "Soundbank.h"

class EntityFactory;
class Weapon
{
public:
	Weapon(Actor* _actor);
	~Weapon();
	virtual void Shoot(EntityFactory* eF);
protected:
	Actor* actor;
	int ammo;
	int clipSize;
	float fireSpeed;
	float timecounter;

};

