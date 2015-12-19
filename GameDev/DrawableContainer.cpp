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

void DrawableContainer::Draw(float dt)
{
	bool cycle = CycleFrames(dt);

	for each (DrawableBehaviour* behaviour in behaviours)
	{
		behaviour->Draw();
		behaviour->CycleFrames(cycle);
	}
}

bool DrawableContainer::CycleFrames(float dt) {
	dtAccumulator += dt;
	bool cycle = dtAccumulator > dtCycleFrame;
	dtAccumulator = static_cast<float>((int)dtAccumulator % (int)dtCycleFrame); //dunno
	return cycle;
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