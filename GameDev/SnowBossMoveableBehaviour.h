#pragma once
#include "MoveableBehaviour.h"
class SnowBossMoveableBehaviour :
	public MoveableBehaviour
{
public:
	SnowBossMoveableBehaviour(std::unordered_map<EntityState, BaseCommand*> _commands);
	~SnowBossMoveableBehaviour();

	SnowBossMoveableBehaviour* EmptyClone();

	virtual void Move(float dt) override;
};

