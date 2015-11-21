#include "BulletCollidableBehaviour.h"


BulletCollidableBehaviour::BulletCollidableBehaviour()
{
}


BulletCollidableBehaviour::~BulletCollidableBehaviour()
{
}

void BulletCollidableBehaviour::Hit(CollidableBehaviour* cb){
	ent->SetHealt(0);
}
CollidableBehaviour* BulletCollidableBehaviour::EmptyClone(){
	return new BulletCollidableBehaviour();
}