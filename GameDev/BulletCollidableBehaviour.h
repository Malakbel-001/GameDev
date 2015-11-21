#pragma once
#include "CollidableBehaviour.h"
#include "Actor.h"
class BulletCollidableBehaviour:
	public CollidableBehaviour
{
public:
	BulletCollidableBehaviour();
	~BulletCollidableBehaviour();
	void Hit(CollidableBehaviour* cb);
	virtual CollidableBehaviour* EmptyClone();

};

