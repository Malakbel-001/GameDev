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
	return new PlantBossMoveableBehaviour(commands);
}

void PlantBossMoveableBehaviour::Move(float dt)
{
	if (!disabled)
		commands[entity->GetState()]->Execute(dynamic_cast<Actor*>(entity));
}