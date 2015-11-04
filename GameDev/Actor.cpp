#include "Actor.h"

#include <iostream>
Actor::Actor()
{
	
	
}

Entity* Actor::EmptyClone(){
	std::cout << "actor";
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
