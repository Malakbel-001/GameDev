#pragma once
#include <vector>
#include "Container.h"
#include "MoveableBehaviour.h"

using namespace std;

class Entity;
class MoveableContainer :
	public Container
{
public:
	MoveableContainer();
	virtual ~MoveableContainer();

	void Add(MoveableBehaviour* behaviour);
	void Move(float dt);
	void Delete(Object* ent);
private:
	std::vector<MoveableBehaviour*> behaviours;
};

