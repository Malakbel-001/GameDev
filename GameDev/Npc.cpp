#include "Npc.h"


Npc::Npc()
{
}
Actor* Npc::EmptyClone(){
	return new Npc();
}

Npc::~Npc()
{
}