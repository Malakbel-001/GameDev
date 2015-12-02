#pragma once
#include "CollidableBehaviour.h"
#include "Actor.h"
class JumpSensorCollidableBehaviour :
	public CollidableBehaviour
{
public:
	JumpSensorCollidableBehaviour();
	~JumpSensorCollidableBehaviour();
	void Hit(CollidableBehaviour* cb);
	void Unhit(CollidableBehaviour* cb);
	virtual CollidableBehaviour* EmptyClone();
};

