#include "Weapon.h"

Weapon::Weapon(Actor* _actor)
{
	ammo = 100;
	clipSize = 10;
	actor = _actor;
	fireSpeed = 250;
	timecounter = 0;
}


Weapon::~Weapon()
{
}

float Weapon::GetAttackSpeed()
{
	return fireSpeed;
}

float Weapon::GetTimeCounter()
{
	return timecounter;
}

void Weapon::SetAttackSpeed(float speed)
{
	fireSpeed = speed;
}

void Weapon::SetTimeCounter(float time)
{
	timecounter = time;
}

void Weapon::Shoot(EntityFactory* eF){

	
	if (SDL_GetTicks() > timecounter + fireSpeed){


		eF->CreateBullet(actor->GetXPos(), actor->GetYPos(), 5, 5, 20,b2Vec2(1000,0) ,EntityType::BULLET);
		
		timecounter = SDL_GetTicks();
	}
}