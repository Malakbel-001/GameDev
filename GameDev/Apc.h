#pragma once
#include "Npc.h"
class Apc :
	public Npc
{
public:
	Apc(EntityFactory* _factory);
	~Apc();

	int GetTroopsCount();
	void SetTroopsCount(int count);
	void AddTroopsCount();
	virtual Actor* EmptyClone();
private:
	int troopsCount;
};

