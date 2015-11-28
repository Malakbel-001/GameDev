#include "Npc.h"


Npc::Npc()
{
	attackSpeed = 200;
	timecounter = 0;
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

void Npc::Attack()
{
	if (SDL_GetTicks() > timecounter + attackSpeed){


		eF->CreateBullet(GetXPos(), GetYPos(), 5, 5, 20, b2Vec2(1000, 0), EntityType::BULLET);

		timecounter = SDL_GetTicks();
	}
}