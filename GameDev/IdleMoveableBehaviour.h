#pragma once
#include "MoveableBehaviour.h"
class IdleMoveableBehaviour :
	public MoveableBehaviour
{
public:
	IdleMoveableBehaviour(std::unordered_map<EntityState, BaseCommand*> _commands);
	~IdleMoveableBehaviour();

	IdleMoveableBehaviour* EmptyClone();

	virtual void Move(float dt) override;
};

