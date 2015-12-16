#include "StepCollidableBehaviour.h"


StepCollidableBehaviour::StepCollidableBehaviour()
{
}


StepCollidableBehaviour::~StepCollidableBehaviour()
{
}

void StepCollidableBehaviour::Hit(CollidableBehaviour* cb){

	if (cb){
		switch (cb->GetActor()->GetType()){
		case EntityType::BULLET:
			break;

		default:

			ent->SetHealth(ent->GetHealth() - cb->GetActor()->GetDamage());
			//TODO different sound
			ent->SetNumFootContacts(ent->GetNumFootContacts() + 1);



			break;
		}
	}
	else{
		ent->SetNumFootContacts(ent->GetNumFootContacts() + 1);

	}
}

void StepCollidableBehaviour::Unhit(CollidableBehaviour* cb){
	if (cb){
		switch (cb->GetActor()->GetType()){
		case EntityType::BULLET:
			break;

		default:
			ent->SetNumFootContacts(ent->GetNumFootContacts() - 1);
			break;
		}
	}
	else{
		ent->SetNumFootContacts(ent->GetNumFootContacts() - 1);
	}
}
CollidableBehaviour* StepCollidableBehaviour::EmptyClone(){
	return new StepCollidableBehaviour();
}