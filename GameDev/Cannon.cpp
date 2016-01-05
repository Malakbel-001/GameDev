#include "Cannon.h"
#include "EntityFactory.h"

Cannon::Cannon()
{
	ammo = 100;
	maxAmmo = 150;
	fireSpeed = 800;
}


Cannon::~Cannon()
{
}

void Cannon::Shoot(EntityFactory* eF){


	if (SDL_GetTicks() > timecounter + fireSpeed){
			bool dir = false;
			if (vec.x == 0 && vec.y == 0){
				vec.x = 1000;
				dir = true;
			}

			SoundBank::GetInstance()->PlaySFX(SoundEffectType::CANNON);

			eF->CreateBullet(actor->GetBody()->GetWorldCenter().x + 6 + vec.x / 200, actor->GetBody()->GetWorldCenter().y + vec.y / 200, 1, 1, 100, vec, EntityType::BULLET);
			eF->CreateBullet(actor->GetBody()->GetWorldCenter().x + 6 + vec.x / 200, actor->GetBody()->GetWorldCenter().y + 1 + vec.y / 200, 1, 1, 100, vec, EntityType::BULLET);
			cout << actor->GetBody()->GetWorldCenter().x + vec.x / 200 << endl;
			cout << actor->GetBody()->GetWorldCenter().y + vec.y / 200 << endl;


			if (dir){
				vec.x = 0;

			}
			timecounter = SDL_GetTicks();
	}
}

Weapon* Cannon::EmptyClone(){
	return new Cannon;
}