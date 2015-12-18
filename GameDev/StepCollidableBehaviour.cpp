#include "StepCollidableBehaviour.h"
#include <iostream>

StepCollidableBehaviour::StepCollidableBehaviour()
{
	steps = 0;
}


StepCollidableBehaviour::~StepCollidableBehaviour()
{
}

void StepCollidableBehaviour::Hit(CollidableBehaviour* cb){
	steps++;
}

void StepCollidableBehaviour::Unhit(CollidableBehaviour* cb){
	steps--;
	
	if (steps == 0)
	{
		b2Vec2 vec = ent->GetBody()->GetLinearVelocity();
		if (vec.x >= 0)
		{
			vec.x = -vec.x;
		}
		else
		{
			vec.x = fabs(vec.x);
		}

		ent->GetBody()->SetLinearVelocity(vec);
	}
}
CollidableBehaviour* StepCollidableBehaviour::EmptyClone(){
	return new StepCollidableBehaviour();
}
