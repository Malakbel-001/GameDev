#pragma once
#include "Actor.h"

class Npc :
	public Actor
{
public:
	Npc();
	~Npc();
	virtual Entity* EmptyClone();
};

