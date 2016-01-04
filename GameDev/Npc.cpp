#include "Npc.h"
#include "EntityFactory.h"

Npc::Npc(EntityFactory* _factory)
{
	score = 0;
	factory = _factory;
}
Actor* Npc::EmptyClone(){
	return new Npc(factory);
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

EntityFactory* Npc::GetFactory()
{
	return factory;
}