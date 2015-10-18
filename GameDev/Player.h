#pragma once
#include "Actor.h"

class Player :
	public Actor
{
public:
	Player();
	~Player();
	virtual Entity* EmptyClone();
};

