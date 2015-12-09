#pragma once
#include <vector>
#include "Container.h"
#include "MoveableBehaviour.h"

class MoveableContainer :
	public Container
{
public:
	MoveableContainer();
	virtual ~MoveableContainer();

	void Add(MoveableBehaviour* behaviour);
	void Move();
	void Delete(MoveableBehaviour* behaviour);
private:
	std::vector<MoveableBehaviour*> behaviours;
};

