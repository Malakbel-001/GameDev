#pragma once
#include "CollidableBehaviour.h"
class AmmoCollidableBehaviour :
	public CollidableBehaviour
{
public:
	AmmoCollidableBehaviour();
	~AmmoCollidableBehaviour();
	virtual void Hit(CollidableBehaviour* cb);
	virtual CollidableBehaviour* EmptyClone();
};

