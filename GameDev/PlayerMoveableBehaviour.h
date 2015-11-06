#pragma once
#include "MoveableBehaviour.h"

class PlayerMoveableBehaviour : public MoveableBehaviour
{
public:
	PlayerMoveableBehaviour();
	~PlayerMoveableBehaviour();

	void Move();
	void Test() {};
};

