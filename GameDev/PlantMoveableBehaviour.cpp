#include "PlantMoveableBehaviour.h"
#include "Npc.h"

PlantMoveableBehaviour::PlantMoveableBehaviour()
{
}


PlantMoveableBehaviour::~PlantMoveableBehaviour()
{
}

PlantMoveableBehaviour* PlantMoveableBehaviour::EmptyClone()
{
	return new PlantMoveableBehaviour();
}

void PlantMoveableBehaviour::Move(float dt)
{
	auto plant = dynamic_cast<Npc*>(entity);
	b2Vec2 vel = plant->GetBody()->GetLinearVelocity();	
	vel.x = vel.x - 0.1;
	plant->GetBody()->SetLinearVelocity(vel);
}