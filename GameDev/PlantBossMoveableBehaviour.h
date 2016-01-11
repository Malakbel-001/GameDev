#pragma once
#include "MoveableBehaviour.h"
class PlantBossMoveableBehaviour :
	public MoveableBehaviour
{
public:
	PlantBossMoveableBehaviour(std::unordered_map<EntityState, BaseCommand*> _commands);
	~PlantBossMoveableBehaviour();

	PlantBossMoveableBehaviour* EmptyClone();

	virtual void Move(float dt) override;
};

