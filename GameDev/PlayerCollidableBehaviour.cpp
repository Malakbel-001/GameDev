#include "PlayerCollidableBehaviour.h"
#include "Player.h"

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
			break;
		case EntityType::MECH:
			dynamic_cast<Player*>(ent)->SetVehicle(dynamic_cast<Player*>(cb->GetActor()));
			break;
		case EntityType::TANK:
			dynamic_cast<Player*>(ent)->SetVehicle(dynamic_cast<Player*>(cb->GetActor()));
			break;
		case EntityType::PLANT:
			ent->SetHealth(ent->GetHealth() - cb->GetActor()->GetDamage());
			break;
		default:

			
			//TODO different sound
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
			break;
		case EntityType::TANK:
			dynamic_cast<Player*>(ent)->SetVehicle(nullptr);
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