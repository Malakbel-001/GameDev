#pragma once
#include "Npc.h"
class Apc :
	public Npc
{
public:
	Apc(EntityFactory* _factory);
	~Apc();

	vector<Actor*> GetTroops();
	void SetTroops(vector<Actor*> troops);
	void AddTroops(Actor* passenger);
	void RemoveTroops(Actor* passenger);
	virtual Actor* EmptyClone();

private:
	vector<Actor*> passengers;
};

