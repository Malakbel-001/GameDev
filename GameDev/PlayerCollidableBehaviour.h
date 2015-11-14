#pragma once
#include "Actor.h"
#include "CollidableBehaviour.h"
#include "SoundBank.h"

class PlayerCollidableBehaviour :
	public CollidableBehaviour
{
public:
	PlayerCollidableBehaviour();
	~PlayerCollidableBehaviour();
	void Hit(int dmg);
	virtual CollidableBehaviour* EmptyClone();

};

