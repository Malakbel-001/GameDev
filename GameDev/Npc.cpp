#include "Npc.h"
#include "EntityFactory.h"

Npc::Npc(EntityFactory* _factory)
{
	score = 0;
	factory = _factory;
	vehicle = nullptr;
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

void Npc::SetHealth(int _health){

	if (_health <= 0){
		dead = true;
		health = _health;

	
	}
	else if (_health > maxHealth) {
		health = maxHealth;
	}
	else{
		health = _health;
	}
}

void Npc::SetVehicle(Npc* _vehicle)
{
	vehicle = _vehicle;
}

Npc* Npc::GetVehicle()
{
	return vehicle;
}