#pragma once
#include "CollidableBehaviour.h"
#include "Actor.h"
#include "SoundBank.h"
class EnemyCollidableBehaviour :
	public CollidableBehaviour
{
public:
	EnemyCollidableBehaviour();
	~EnemyCollidableBehaviour();	
	virtual void Hit(CollidableBehaviour* cb);
	virtual CollidableBehaviour* EmptyClone();
};

