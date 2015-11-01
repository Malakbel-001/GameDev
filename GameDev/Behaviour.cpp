#include "Behaviour.h"


Behaviour::Behaviour()
{
}


Behaviour::~Behaviour()
{
}

Behaviour* Behaviour::EmptyClone()
{	
	return new Behaviour();
}