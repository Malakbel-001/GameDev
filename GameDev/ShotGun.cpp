#include "ShotGun.h"
#include "EntityFactory.h"

ShotGun::ShotGun()
{


	ammo = 100;
	maxAmmo = 150;
	fireSpeed = 500;

}


ShotGun::~ShotGun()
{
}
void ShotGun::Shoot(EntityFactory* eF){


	if (SDL_GetTicks() > timecounter + fireSpeed){
		if (ammo > 2){
			bool dir = false;
			if (vec.x == 0 && vec.y == 0){
				vec.x = 1000;
				dir = true;
			}

			SoundBank::GetInstance()->PlaySFX(SoundEffectType::SHOTGUN);

			eF->CreateBullet(actor->GetBody()->GetWorldCenter().x + vec.x / 200, actor->GetBody()->GetWorldCenter().y + vec.y / 200, 1, 1, 20, vec, EntityType::BULLET);

			b2Vec2 temp = (vec);


			temp.x = temp.x - (temp.y / 10);
			temp.y = temp.y - (temp.x / 10);
			eF->CreateBullet(actor->GetBody()->GetWorldCenter().x + temp.x / 200, actor->GetBody()->GetWorldCenter().y + temp.y / 200, 1, 1, 20, temp, EntityType::BULLET);
			temp = (vec);

			temp.x = temp.x + (temp.y / 10);
			temp.y = temp.y + (temp.x / 10);
			eF->CreateBullet(actor->GetBody()->GetWorldCenter().x + temp.x / 200, actor->GetBody()->GetWorldCenter().y + temp.y / 200, 1, 1, 20, temp, EntityType::BULLET);
			if (dir){
				vec.x = 0;

			}
			ammo = ammo - 3;
			timecounter = SDL_GetTicks();
		}
	}
}

Weapon* ShotGun::EmptyClone(){
	return new ShotGun;
}