#include "AmmoCollidableBehaviour.h"

#include "Weapon.h"

AmmoCollidableBehaviour::AmmoCollidableBehaviour()
{
}
void AmmoCollidableBehaviour::Hit(CollidableBehaviour* cb){
	if (cb){
		switch (cb->GetActor()->GetType()){
		case EntityType::PLAYER:
			ent->SetHealth(0);
			cb->GetActor()->GetCurrentWeapon()->AddAmmo(10);
			//ent->GetCurrentWeapon()->AddAmmo(100);

			break;
		default:
			break;
		}
	}
}
CollidableBehaviour* AmmoCollidableBehaviour::EmptyClone(){
	return new AmmoCollidableBehaviour;
}

AmmoCollidableBehaviour::~AmmoCollidableBehaviour()
{
}
