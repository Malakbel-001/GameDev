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
	std::unordered_map<EntityState, BaseCommand*> clone;

	for each (auto var in commands)
	{
		clone[var.first] = commands[var.first]->EmptyClone();
	}

	return new PlantMoveableBehaviour(clone);
}

void PlantMoveableBehaviour::Move(float dt)
{	
	if (!disabled)
		commands[entity->GetState()]->Execute(dynamic_cast<Actor*>(entity));
}