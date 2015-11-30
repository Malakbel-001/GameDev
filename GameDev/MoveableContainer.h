#pragma once
#include <vector>
#include "SDL.h"
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
	void Delete(Entity* behaviour);
private:
	vector<MoveableBehaviour*> behaviours;
};

