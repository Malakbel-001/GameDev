#pragma once
#include "MoveableBehaviour.h"
class ApcMoveableBehaviour :
	public MoveableBehaviour
{
public:
	ApcMoveableBehaviour(std::unordered_map<EntityState, BaseCommand*> _commands);
	~ApcMoveableBehaviour();

	ApcMoveableBehaviour* EmptyClone();

	virtual void Move(float dt) override;
};

