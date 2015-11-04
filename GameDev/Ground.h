#pragma once
#include "Entity.h"
class Ground :
	public Entity
{
public:
	Ground();
	~Ground();
	virtual Entity* EmptyClone();
};

