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
	return new ApcMoveableBehaviour(commands);
}

void ApcMoveableBehaviour::Move(float dt)
{
	if (!disabled)
		commands[entity->GetState()]->Execute(dynamic_cast<Actor*>(entity));
}