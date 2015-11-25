#pragma once
#include "Entity.h"
#include "ActorState.h"


class Actor :
	public Entity
{
public:
	Actor();
	virtual ~Actor();

	virtual Entity* EmptyClone();
};

