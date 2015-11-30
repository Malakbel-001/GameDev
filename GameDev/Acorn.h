#pragma once
#include "Actor.h"

class Acorn :
	public Actor
{
public:
	Acorn();
	~Acorn();

	virtual Acorn* EmptyClone();
};

