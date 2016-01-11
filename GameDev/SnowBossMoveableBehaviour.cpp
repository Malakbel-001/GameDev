#include "SnowBossMoveableBehaviour.h"
#include "Npc.h"

SnowBossMoveableBehaviour::SnowBossMoveableBehaviour(std::unordered_map<EntityState, BaseCommand*> _commands) : MoveableBehaviour(_commands)
{
}


SnowBossMoveableBehaviour::~SnowBossMoveableBehaviour()
{
}

SnowBossMoveableBehaviour* SnowBossMoveableBehaviour::EmptyClone()
{
	return new SnowBossMoveableBehaviour(commands);
}

void SnowBossMoveableBehaviour::Move(float dt)
{
	if (!disabled)
		commands[entity->GetState()]->Execute(dynamic_cast<Actor*>(entity));
}
