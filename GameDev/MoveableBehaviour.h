#pragma once
#include "Behaviour.h"

class MoveableBehaviour :
	public Behaviour
{
public:
	MoveableBehaviour();
	virtual ~MoveableBehaviour();

	virtual void Move();
};


















