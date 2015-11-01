#pragma once
#include "Entity.h"
class Ground :
	public Entity
{
public:
	Ground();
	virtual ~Ground();
	virtual Entity* EmptyClone();
};

