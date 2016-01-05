#include "Apc.h"


Apc::Apc(EntityFactory* _factory) : Npc(_factory)
{
}


Apc::~Apc()
{
}

vector<Actor*> Apc::GetTroops()
{
	return passengers;
}

void Apc::SetTroops(vector<Actor*> troops)
{
	passengers = troops;
}

void Apc::AddTroops(Actor* passenger)
{
	passengers.push_back(passenger);
}

void Apc::RemoveTroops(Actor* passenger)
{
	passengers.erase(std::remove(passengers.begin(), passengers.end(), passenger), passengers.end());
}

Actor* Apc::EmptyClone(){
	return new Apc(factory);
}
