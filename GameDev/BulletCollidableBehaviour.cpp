#include "BulletCollidableBehaviour.h"


BulletCollidableBehaviour::BulletCollidableBehaviour()
{
}


BulletCollidableBehaviour::~BulletCollidableBehaviour()
{
}

void BulletCollidableBehaviour::Hit(CollidableBehaviour* cb){
	if (cb){
		switch (cb->GetActor()->GetType()){
		case EntityType::PLAYER:

			break;
		default:
			ent->SetHealt(0);
			break;
		}
	}
	else{
		ent->SetHealt(0);
	}
	
}
CollidableBehaviour* BulletCollidableBehaviour::EmptyClone(){
	return new BulletCollidableBehaviour();
}