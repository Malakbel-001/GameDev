#pragma once
#include "MoveableBehaviour.h"
class IdleMoveableBehaviour :
	public MoveableBehaviour
{
public:
	IdleMoveableBehaviour();
	~IdleMoveableBehaviour();

	IdleMoveableBehaviour* EmptyClone();

	virtual void Move() override;
};

