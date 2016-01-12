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
	std::unordered_map<EntityState, BaseCommand*> clone;

	for each (auto var in commands)
	{
		clone[var.first] = commands[var.first]->EmptyClone();
	}
	return new SnowBossMoveableBehaviour(clone);
}

void SnowBossMoveableBehaviour::Move(float dt)
{
	if (!disabled)
		commands[entity->GetState()]->Execute(dynamic_cast<Actor*>(entity));
}
