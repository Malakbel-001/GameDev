#pragma once
#include "Actor.h"

class Player :
	public Actor
{
public:
	Player();

	virtual ~Player();
	virtual Entity* EmptyClone();

};

