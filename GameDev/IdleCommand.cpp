#include "IdleCommand.h"
#include "Actor.h"

IdleCommand::IdleCommand()
{
}


IdleCommand::~IdleCommand()
{
}

void IdleCommand::Execute(Actor* actor)
{
	b2Vec2 dir = actor->GetDirection();
	if (dir.x != 0)
	{
		dir.x = 0;
		actor->SetDirection(dir);
	}	
}