 #include "MoveableBehaviour.h"
#include "Npc.h"
#include "IdleCommand.h"
#include "DefaultPatrolCommand.h"

MoveableBehaviour::MoveableBehaviour(std::unordered_map<EntityState, BaseCommand*> _commands)
{
	commands = _commands;
	disabled = false;
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
	std::unordered_map<EntityState, BaseCommand*> clone;

	for each (auto var in commands)
	{
		clone[var.first] = commands[var.first]->EmptyClone();
	}

	return new MoveableBehaviour(clone);
}

void MoveableBehaviour::Move(float dt)
{
	
}

bool MoveableBehaviour::GetDisabled()
{
	return disabled;
}

void MoveableBehaviour::SetDisabled(bool disable)
{
	disabled = disable;
}