#include "CollidableBehaviour.h"
#include "Actor.h"

CollidableBehaviour::CollidableBehaviour()
{
	
}


CollidableBehaviour::~CollidableBehaviour()
{
}

CollidableBehaviour* CollidableBehaviour::EmptyClone()
{
	return new CollidableBehaviour();
}
void CollidableBehaviour::Hit(int dmg){
	printf("Hit");


}

void CollidableBehaviour::Init(Actor* _ent){
	ent = _ent;
}
int CollidableBehaviour::GetHitDmg(){
	return ent->GetDamage();
}