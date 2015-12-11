#include "MoveableContainer.h"
#include "Entity.h"

MoveableContainer::MoveableContainer()
{
	behaviours = vector<MoveableBehaviour*>();
}


MoveableContainer::~MoveableContainer()
{
}

void MoveableContainer::Add(MoveableBehaviour* behaviour)
{
	behaviours.push_back(behaviour);
}

void MoveableContainer::Move(float dt)
{
	for each (MoveableBehaviour* behaviour in behaviours)
	{
		behaviour->Move(dt);
	}
}
void MoveableContainer::Delete(Entity* ent){
	bool found = false;
	size_t i = 0;
	for (; i < behaviours.size() && !found; i++)
	{
		if (behaviours[i]->GetEntity() == ent){

			found = true;
		}

	}
	i = i - 1;
	delete behaviours[i];
	behaviours.erase(behaviours.begin() + i);

}