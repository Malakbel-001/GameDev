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
	if (!disabled)
		commands[entity->GetState()]->Execute(dynamic_cast<Actor*>(entity));
}