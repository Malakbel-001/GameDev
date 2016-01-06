#include "DrawableContainer.h"
#include "Entity.h"

DrawableContainer::DrawableContainer()
{
	behaviours = vector<DrawableBehaviour*>();
}


DrawableContainer::~DrawableContainer() { 
	Cleanup();
}

void DrawableContainer::Cleanup() {
	for each (DrawableBehaviour* var in behaviours)
	{
		delete var;
	}
	behaviours.clear();
}

void DrawableContainer::Add(DrawableBehaviour* behaviour)
{
	behaviours.push_back(behaviour);
}

void DrawableContainer::Draw(float dt, float manipulatorSpeed)
{
	bool cycle = CycleFrames(dt, manipulatorSpeed);

	for each (DrawableBehaviour* behaviour in behaviours)
	{
		behaviour->Draw(cycle);
	}
}

bool DrawableContainer::CycleFrames(float dt, float manipulatorSpeed) {
	dtAccumulator += dt;
	bool cycle = dtAccumulator > dtCycleFrame / manipulatorSpeed;
	dtAccumulator = static_cast<float>((int)dtAccumulator % (int)(dtCycleFrame / manipulatorSpeed)); //dunno
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