#include "BulletCollidableBehaviour.h"


BulletCollidableBehaviour::BulletCollidableBehaviour()
{
}


BulletCollidableBehaviour::~BulletCollidableBehaviour()
{
}

void BulletCollidableBehaviour::Hit(CollidableBehaviour* cb){
	ent->SetHealth(0);
}
CollidableBehaviour* BulletCollidableBehaviour::EmptyClone(){
	return new BulletCollidableBehaviour();
}