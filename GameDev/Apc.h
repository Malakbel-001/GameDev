#pragma once
#include "Npc.h"
class Apc :
	public Npc
{
public:
	Apc(EntityFactory* _factory);
	~Apc();

	
	virtual Actor* EmptyClone();

};

