#include "JumpSensorCollidableBehaviour.h"


JumpSensorCollidableBehaviour::JumpSensorCollidableBehaviour()
{
}
void JumpSensorCollidableBehaviour::Hit(CollidableBehaviour* cb){
	if (cb){
		switch (cb->GetActor()->GetType()){
		case EntityType::PLAYER :
			
			break;
		default:
			ent->SetNumFootContacts(ent->GetNumFootContacts() + 1);
			break;
		}
	}
}
void JumpSensorCollidableBehaviour::Unhit(CollidableBehaviour* cb){
	if (cb){
		switch (cb->GetActor()->GetType()){
		case EntityType::PLAYER:

			break;
		default:
			ent->SetNumFootContacts(ent->GetNumFootContacts() - 1);
			break;
		}
	}


}

CollidableBehaviour* JumpSensorCollidableBehaviour::EmptyClone(){
	return new JumpSensorCollidableBehaviour();
}

JumpSensorCollidableBehaviour::~JumpSensorCollidableBehaviour()
{
}
