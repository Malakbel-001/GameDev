#include "Npc.h"


Npc::Npc()
{
	score = 0;
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

void Npc::SetScore(int _score) {
	score = _score;
}

int Npc::GetScore() {
	return score;
}