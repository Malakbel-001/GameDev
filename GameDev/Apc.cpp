#include "Apc.h"


Apc::Apc(EntityFactory* _factory) : Npc(_factory)
{
}


Apc::~Apc()
{
}


Actor* Apc::EmptyClone(){
	return new Apc(factory);
}
