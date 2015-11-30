#include "PlayerCollidableBehaviour.h"


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
			
		default:
			ent->SetHealth(ent->GetHealth() - cb->GetActor()->GetDamage());
			//TODO different sound
			SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
			break;
		}
	}
}
CollidableBehaviour* PlayerCollidableBehaviour::EmptyClone(){
	return new PlayerCollidableBehaviour();
}