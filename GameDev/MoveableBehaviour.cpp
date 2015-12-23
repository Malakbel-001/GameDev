 #include "MoveableBehaviour.h"
#include "Npc.h"

MoveableBehaviour::MoveableBehaviour(std::unordered_map<EntityState, BaseCommand*> _commands)
{
	commands = _commands;
}


MoveableBehaviour::~MoveableBehaviour()
{
}

void MoveableBehaviour::SetEntity(Object* _entity)
{
	entity = _entity;
}

Object* MoveableBehaviour::GetEntity()
{
	return entity;
}

MoveableBehaviour* MoveableBehaviour::EmptyClone()
{
	return new MoveableBehaviour(commands);
}

void MoveableBehaviour::Move(float dt)
{
	
}
