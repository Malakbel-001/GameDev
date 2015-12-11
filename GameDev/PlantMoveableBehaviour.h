#pragma once
#include "MoveableBehaviour.h"
class PlantMoveableBehaviour :
	public MoveableBehaviour
{
public:
	PlantMoveableBehaviour();
	~PlantMoveableBehaviour();

	PlantMoveableBehaviour* EmptyClone();

	virtual void Move(float dt) override;
};

