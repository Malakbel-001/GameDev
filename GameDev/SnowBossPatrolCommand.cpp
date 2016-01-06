#include "SnowBossPatrolCommand.h"
#include "Actor.h"

SnowBossPatrolCommand::SnowBossPatrolCommand()
{
}


SnowBossPatrolCommand::~SnowBossPatrolCommand()
{
}

void SnowBossPatrolCommand::Execute(Actor* actor)
{
	b2Vec2 dir = actor->GetBody()->GetLinearVelocity();
	if (dir.x >= 0){
		dir.x = dir.x + 0.1;
		dir.y = dir.y - 0.3;
	}
	else{
		dir.x = dir.x - 0.1;
		dir.y = dir.y + 0.3;
	}
	actor->GetBody()->SetLinearVelocity(dir);
}