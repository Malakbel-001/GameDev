#pragma once
#include "Actor.h"

class Weapon;
class Npc :
	public Actor
{
public:
	Npc();
	
	virtual ~Npc();
	virtual Actor* EmptyClone();
	void setBody(b2Body* _body);
	b2Body* GetBody();

	void Attack();
protected:
	float attackSpeed;
	float timecounter;

	Weapon* currentWep = nullptr;
};

