#include "DrawableContainer.h"
#include "Entity.h"

DrawableContainer::DrawableContainer()
{
	behaviours = vector<DrawableBehaviour*>();
}


DrawableContainer::~DrawableContainer() { 
	for each (DrawableBehaviour* var in behaviours)
	{
		delete var;
	}

}

void DrawableContainer::Add(DrawableBehaviour* behaviour)
{
	behaviours.push_back(behaviour);
}

void DrawableContainer::Draw()
{
	for each (DrawableBehaviour* behaviour in behaviours)
	{
		behaviour->Draw();
	}
}
void DrawableContainer::Delete(Entity* ent){
	bool found = false;
	size_t i = 0;
	for (;i < behaviours.size() && !found; i++)
	{
		if (behaviours[i]->GetEntity() == ent){

			found = true;
		}
		
	}
	i = i - 1;
	delete behaviours[i];
	behaviours.erase(behaviours.begin() + i);

}