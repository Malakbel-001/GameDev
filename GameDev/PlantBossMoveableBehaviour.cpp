#include "PlantBossMoveableBehaviour.h"
#include "Npc.h"

PlantBossMoveableBehaviour::PlantBossMoveableBehaviour(std::unordered_map<EntityState, BaseCommand*> _commands) : MoveableBehaviour(_commands)
{
}


PlantBossMoveableBehaviour::~PlantBossMoveableBehaviour()
{
}

PlantBossMoveableBehaviour* PlantBossMoveableBehaviour::EmptyClone()
{
	std::unordered_map<EntityState, BaseCommand*> clone;

	for each (auto var in commands)
	{
		clone[var.first] = commands[var.first]->EmptyClone();
	}

	return new PlantBossMoveableBehaviour(clone);
}

void PlantBossMoveableBehaviour::Move(float dt)
{
	if (!disabled)
		commands[entity->GetState()]->Execute(dynamic_cast<Actor*>(entity));
}