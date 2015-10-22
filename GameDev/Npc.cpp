#include "Npc.h"


Npc::Npc()
{
}
Entity* Npc::EmptyClone(){
	return new Npc();
}

Npc::~Npc()
{
}
