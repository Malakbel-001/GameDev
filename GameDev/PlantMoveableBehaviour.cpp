#include "PlantMoveableBehaviour.h"
#include "Npc.h"
#include "Level.h"

PlantMoveableBehaviour::PlantMoveableBehaviour(std::unordered_map<EntityState, BaseCommand*> _commands) : MoveableBehaviour(_commands)
{
}


PlantMoveableBehaviour::~PlantMoveableBehaviour()
{
}

PlantMoveableBehaviour* PlantMoveableBehaviour::EmptyClone()
{
	return new PlantMoveableBehaviour(commands);
}

void PlantMoveableBehaviour::Move(float dt)
{	
	commands[entity->GetState()]->Execute(dynamic_cast<Actor*>(entity));

	/*auto plant = dynamic_cast<Npc*>(entity);
	auto level = plant->GetLevel();

	b2Vec2 vel = plant->GetBody()->GetLinearVelocity();	
	b2Vec2 dir = plant->GetDirection();
	vel.x = vel.x - 0.1;
	plant->GetBody()->SetLinearVelocity(dir);*/
}