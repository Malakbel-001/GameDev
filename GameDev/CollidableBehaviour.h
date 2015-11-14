#pragma message("collide=able beh")
#pragma once

#include "Behaviour.h"


class Actor;
class CollidableBehaviour :
	public Behaviour
{
public:
	CollidableBehaviour();
	void Init(Actor* _ent);
	virtual ~CollidableBehaviour();
	virtual void Hit(int dmg);
	virtual CollidableBehaviour* EmptyClone();
	int GetHitDmg();
protected:
	Actor* ent;


};

