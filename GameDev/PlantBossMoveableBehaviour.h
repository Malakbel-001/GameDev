#pragma once
#include "MoveableBehaviour.h"
class PlantBossMoveableBehaviour :
	public MoveableBehaviour
{
public:
	PlantBossMoveableBehaviour();
	~PlantBossMoveableBehaviour();

	PlantBossMoveableBehaviour* EmptyClone();

	virtual void Move(float dt) override;
};

