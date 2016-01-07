#include "PlayerCollidableBehaviour.h"
#include "Vehicle.h"

PlayerCollidableBehaviour::PlayerCollidableBehaviour()
{
}


PlayerCollidableBehaviour::~PlayerCollidableBehaviour()
{
}
void PlayerCollidableBehaviour::Hit(CollidableBehaviour* cb){
	
	if (cb){
		switch (cb->GetActor()->GetType()){
		case EntityType::BULLET:
			ent->SetHealth(ent->GetHealth() - cb->GetActor()->GetDamage());
			break;
		case EntityType::MECH:
			dynamic_cast<Player*>(ent)->SetVehicle(dynamic_cast<Player*>(cb->GetActor()));
			ent->SetNumFootContacts(ent->GetNumFootContacts() + 1);
			break;
		case EntityType::TANK:
			dynamic_cast<Player*>(ent)->SetVehicle(dynamic_cast<Player*>(cb->GetActor()));
			ent->SetNumFootContacts(ent->GetNumFootContacts() + 1);
			break;
		default:
			ent->SetHealth(ent->GetHealth() - cb->GetActor()->GetDamage());
			ent->SetNumFootContacts(ent->GetNumFootContacts() + 1);
			
			break;
		}
	}
	else{
		ent->SetNumFootContacts(ent->GetNumFootContacts() + 1);

	}
}

void PlayerCollidableBehaviour::Unhit(CollidableBehaviour* cb){
	if (cb){
		switch (cb->GetActor()->GetType()){
		case EntityType::BULLET:
			break;
		case EntityType::MECH:
			dynamic_cast<Player*>(ent)->SetVehicle(nullptr);
			ent->SetNumFootContacts(ent->GetNumFootContacts() - 1);
			break;
		case EntityType::TANK:
			dynamic_cast<Player*>(ent)->SetVehicle(nullptr);
			ent->SetNumFootContacts(ent->GetNumFootContacts() - 1);
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
CollidableBehaviour* PlayerCollidableBehaviour::EmptyClone(){
	return new PlayerCollidableBehaviour();
}