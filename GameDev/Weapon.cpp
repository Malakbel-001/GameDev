#include "Weapon.h"
#include "EntityFactory.h"

Weapon::Weapon(Actor* _actor)
{
	vec = b2Vec2(0, 1000);
	ammo = 100;
	maxAmmo = 200;
	actor = _actor;
	fireSpeed = 250;
	timecounter = 0;
}


Weapon::~Weapon()
{
}
void Weapon::AddAmmo(int _ammo){
	if (!((ammo + _ammo) > maxAmmo)){
		ammo = ammo + _ammo;
	}
	else{
		ammo = maxAmmo;
	}

}
void Weapon::Shoot(EntityFactory* eF){

	
	if (SDL_GetTicks() > timecounter + fireSpeed){
		if (ammo > 0){



			eF->CreateBullet(actor->GetXPos(), actor->GetYPos(), 5, 5, 20, vec, EntityType::BULLET);
			ammo--;
			timecounter = SDL_GetTicks();
		}
	}
}