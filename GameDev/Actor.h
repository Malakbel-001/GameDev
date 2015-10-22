#pragma once
#include "Entity.h"

class Actor :
	public Entity
{
public:
	Actor();

	virtual Entity* EmptyClone();

	virtual ~Actor();

};

