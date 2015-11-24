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
	void Hit(CollidableBehaviour* cb);
	virtual CollidableBehaviour* EmptyClone();

};

