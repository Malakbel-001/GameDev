#include "Actor.h"


Actor::Actor()
{
}


Actor::~Actor()
{
}

void Actor::SetState(ActorState* new_state)
{
	state = new_state;
}

ActorState* Actor::GetState()
{
	return state;
}