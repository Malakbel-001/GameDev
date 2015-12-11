#include "PlantBossMoveableBehaviour.h"
#include "Npc.h"

PlantBossMoveableBehaviour::PlantBossMoveableBehaviour()
{
}


PlantBossMoveableBehaviour::~PlantBossMoveableBehaviour()
{
}

PlantBossMoveableBehaviour* PlantBossMoveableBehaviour::EmptyClone()
{
	return new PlantBossMoveableBehaviour();
}

void PlantBossMoveableBehaviour::Move(float dt)
{
	auto plant = dynamic_cast<Npc*>(entity);
	//plant->
}