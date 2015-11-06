#pragma once
#include "Actor.h"

class Npc :
	public Actor
{
public:
	Npc();

	virtual ~Npc();
	virtual Entity* EmptyClone();
	void setBody(b2Body* _body);
	b2Body* GetBody();
};

