#include "MoveableContainer.h"


MoveableContainer::MoveableContainer()
{
}


MoveableContainer::~MoveableContainer()
{
}

void MoveableContainer::Add(MoveableBehaviour* behaviour)
{
	behaviours.push_back(behaviour);
}

void MoveableContainer::Move()
{
	for each (MoveableBehaviour* behaviour in behaviours)
	{
		behaviour->Move();
	}
}
void MoveableContainer::Delete(MoveableBehaviour* b){
	bool found = false;
	size_t i = 0;
	for (; i < behaviours.size() && !found; i++)
	{
		if (behaviours[i] == b){

			found = true;
		}

	}
	i = i - 1;
	delete behaviours[i];
	behaviours.erase(behaviours.begin() + i);

}