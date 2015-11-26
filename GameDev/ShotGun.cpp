#include "ShotGun.h"
#include "EntityFactory.h"

ShotGun::ShotGun(Actor* ent) : Weapon(ent)
{
	vec = b2Vec2(0, 1000);
	ammo = 75;
	maxAmmo = 100;
	fireSpeed = 500;
	
}


ShotGun::~ShotGun()
{
}
void ShotGun::Shoot(EntityFactory* eF){


	if (SDL_GetTicks() > timecounter + fireSpeed){
		if (ammo > 2){

			eF->CreateBullet(actor->GetXPos(), actor->GetYPos() - 5, 5, 5, 20, b2Vec2(1000, -200), EntityType::BULLET);
			eF->CreateBullet(actor->GetXPos() + 5, actor->GetYPos(), 5, 5, 20, b2Vec2(1000, 0), EntityType::BULLET);
			eF->CreateBullet(actor->GetXPos(), actor->GetYPos() + 5, 5, 5, 20, b2Vec2(1000, 200), EntityType::BULLET);
			timecounter = SDL_GetTicks();
			ammo = ammo - 3;
		}
	}
}