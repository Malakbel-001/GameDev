#pragma once
#include "MoveableBehaviour.h"
class PlantMoveableBehaviour :
	public MoveableBehaviour
{
public:
	PlantMoveableBehaviour(std::unordered_map<EntityState, BaseCommand*> _commands);
	~PlantMoveableBehaviour();

	PlantMoveableBehaviour* EmptyClone();

	virtual void Move(float dt) override;
};

