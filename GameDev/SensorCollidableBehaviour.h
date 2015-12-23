#pragma once
#include "CollidableBehaviour.h"
#include "Actor.h"

class SensorCollidableBehaviour :
	public CollidableBehaviour
{
public:
	SensorCollidableBehaviour();
	~SensorCollidableBehaviour();
	void Hit(CollidableBehaviour* cb);
	void Unhit(CollidableBehaviour* cb);
	virtual CollidableBehaviour* EmptyClone();
};

