#include "SensorCollidableBehaviour.h"


SensorCollidableBehaviour::SensorCollidableBehaviour()
{
}


SensorCollidableBehaviour::~SensorCollidableBehaviour()
{
}

void SensorCollidableBehaviour::Hit(CollidableBehaviour* cb){
	//ent->SetState(EntityState::PATROL);
	printf("hit");
}

void SensorCollidableBehaviour::Unhit(CollidableBehaviour* cb){
	//ent->SetState(EntityState::IDLE);
	printf("unhit");
}

CollidableBehaviour* SensorCollidableBehaviour::EmptyClone(){
	return new SensorCollidableBehaviour();
}