#include "ApcMoveableBehaviour.h"
#include "Npc.h"
#include "Level.h"

ApcMoveableBehaviour::ApcMoveableBehaviour(std::unordered_map<EntityState, BaseCommand*> _commands) : MoveableBehaviour(_commands)
{
}


ApcMoveableBehaviour::~ApcMoveableBehaviour()
{
}

ApcMoveableBehaviour* ApcMoveableBehaviour::EmptyClone()
{
	std::unordered_map<EntityState, BaseCommand*> clone;

	for each (auto var in commands)
	{
		clone[var.first] = commands[var.first]->EmptyClone();
	}
	return new ApcMoveableBehaviour(clone);
}

void ApcMoveableBehaviour::Move(float dt)
{
	if (!disabled)
		commands[entity->GetState()]->Execute(dynamic_cast<Actor*>(entity));
}