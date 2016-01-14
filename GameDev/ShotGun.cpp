#include "ShotGun.h"
#include "EntityFactory.h"

ShotGun::ShotGun()
{


	ammo = 100;
	maxAmmo = 150;
	fireSpeed = 500;
	weaponDmg = 20;

}


ShotGun::~ShotGun()
{
}
bool ShotGun::Shoot(EntityFactory* eF, float accumulatedDt, float manipulatorSpeed){
	if (accumulatedDt > (fireSpeed/manipulatorSpeed)){
		if (ammo > 2){
			bool dir = false;
			if (vec.x == 0 && vec.y == 0){
				SetXVec(defaultShootingDirection.x);
				SetYVec(defaultShootingDirection.y);
				dir = true;
			}

			if (actor->GetFlipped())
			{
				SetXVec(-100);
			}


			SoundBank::GetInstance()->PlaySFX(SoundEffectType::SHOTGUN);	
			eF->CreateBullet(actor->GetBody()->GetWorldCenter().x + vec.x / 200, actor->GetBody()->GetWorldCenter().y + vec.y / 200, 1, 1, weaponDmg, vec, actor->GetBody()->GetFixtureList()->GetFilterData().categoryBits, EntityType::BULLET);


			b2Vec2 temp = (vec);


			temp.x = temp.x - (temp.y / 10);
			temp.y = temp.y - (temp.x / 10);
			eF->CreateBullet(actor->GetBody()->GetWorldCenter().x + temp.x / 200, actor->GetBody()->GetWorldCenter().y + temp.y / 200, 1, 1, weaponDmg, temp, actor->GetBody()->GetFixtureList()->GetFilterData().categoryBits, EntityType::BULLET);

			temp = (vec);

			temp.x = temp.x + (temp.y / 10);
			temp.y = temp.y + (temp.x / 10);
			eF->CreateBullet(actor->GetBody()->GetWorldCenter().x + temp.x / 200, actor->GetBody()->GetWorldCenter().y + temp.y / 200, 1, 1, weaponDmg, temp, actor->GetBody()->GetFixtureList()->GetFilterData().categoryBits, EntityType::BULLET);

			if (dir){
				vec.x = 0;

			}
			ammo = ammo - 3;

			return true;
		}
	}

	return false;
}

Weapon* ShotGun::EmptyClone(){
	return new ShotGun;
}