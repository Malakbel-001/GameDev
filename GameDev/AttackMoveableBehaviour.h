#pragma once
#include "MoveableBehaviour.h"
class AttackMoveableBehaviour :
	public MoveableBehaviour
{
public:
	AttackMoveableBehaviour();
	~AttackMoveableBehaviour();

	virtual AttackMoveableBehaviour* EmptyClone() override;
	virtual void Move() override;
};

