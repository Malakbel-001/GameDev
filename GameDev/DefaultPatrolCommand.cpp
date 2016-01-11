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
	b2Vec2 dir = actor->GetBody()->GetLinearVelocity();
	if (dir.x >= 0)
		dir.x = dir.x + 0.6;
	else
		dir.x = dir.x - 0.6;

	actor->GetBody()->SetLinearVelocity(dir);
}