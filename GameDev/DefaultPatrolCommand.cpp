#include "DefaultPatrolCommand.h"
#include "Actor.h"

DefaultPatrolCommand::DefaultPatrolCommand()
{
}


DefaultPatrolCommand::~DefaultPatrolCommand()
{
}

void DefaultPatrolCommand::Execute(Actor* actor)
{
	b2Vec2 dir = actor->GetDirection();
	if (dir.x == 0)
	{
		dir.x = 1;
		actor->SetDirection(dir);
	}
}