#pragma once
#include "Player.h"
#include "Soundbank.h"
#include "EntityFactory.h"

class Weapon
{
public:
	Weapon(Actor* _actor);
	~Weapon();
	virtual void Shoot(EntityFactory* eF);

	float GetAttackSpeed();
	float GetTimeCounter();

	void SetAttackSpeed(float speed);
	void SetTimeCounter(float time);
protected:
	Actor* actor;
	int ammo;
	int clipSize;
	float fireSpeed;
	float timecounter;

};

