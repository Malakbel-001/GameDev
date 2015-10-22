#pragma once
#include "Actor.h"

class Npc :
	public Actor
{
public:
	Npc();

	virtual ~Npc();
	virtual Entity* EmptyClone();

};

