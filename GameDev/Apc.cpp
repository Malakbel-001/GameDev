#include "Apc.h"


Apc::Apc(EntityFactory* _factory) : Npc(_factory)
{
	troopsCount = 0;
}


Apc::~Apc()
{
}

int Apc::GetTroopsCount()
{
	return troopsCount;
}

void Apc::SetTroopsCount(int count)
{
	troopsCount = count;
}

void Apc::AddTroopsCount()
{
	troopsCount = troopsCount++;
}

Actor* Apc::EmptyClone(){
	return new Apc(factory);
}
