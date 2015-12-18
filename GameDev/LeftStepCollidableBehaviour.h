#pragma once
#include "Actor.h"
#include "CollidableBehaviour.h"

class LeftStepCollidableBehaviour :
	public CollidableBehaviour
{
public:
	LeftStepCollidableBehaviour();
	~LeftStepCollidableBehaviour();
	void Hit(CollidableBehaviour* cb);
	void Unhit(CollidableBehaviour* cb);
	virtual CollidableBehaviour* EmptyClone();

	void SetLeft(bool l);

private:
	int steps;
	bool left;
};

