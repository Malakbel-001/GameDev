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
	virtual void Hit(CollidableBehaviour* cb);
	virtual void Unhit(CollidableBehaviour* cb);
	virtual CollidableBehaviour* EmptyClone();
	int GetHitDmg();
	Actor* GetActor();
protected:
	Actor* ent;


};

