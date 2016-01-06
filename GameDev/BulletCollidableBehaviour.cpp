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
		default:
			ent->SetHealth(0);
			break;
		}
	}
	else{
		ent->SetHealth(0);
	}
	

}
CollidableBehaviour* BulletCollidableBehaviour::EmptyClone(){
	return new BulletCollidableBehaviour();
}