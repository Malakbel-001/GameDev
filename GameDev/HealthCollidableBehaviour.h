#pragma once
#include "CollidableBehaviour.h"
class HealthCollidableBehaviour :
	public CollidableBehaviour
{
public:
	HealthCollidableBehaviour();
	~HealthCollidableBehaviour();
	virtual void Hit(CollidableBehaviour* cb);
	virtual CollidableBehaviour* EmptyClone();
};

