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

void Npc::setBody(b2Body* _body)
{
	body = _body;
}

b2Body* Npc::GetBody()
{
	return body;
}