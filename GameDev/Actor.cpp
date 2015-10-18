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
