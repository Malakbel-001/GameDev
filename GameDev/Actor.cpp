#include "Actor.h"

Actor::Actor()
{
	
	
}

Entity* Actor::EmptyClone(){

	return new Actor();
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
