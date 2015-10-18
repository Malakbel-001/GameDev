#pragma once
#include "Entity.h"

class Actor :
	public Entity
{
public:
	Actor();
	~Actor();
	virtual Entity* EmptyClone();
};

