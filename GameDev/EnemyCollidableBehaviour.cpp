#include "EnemyCollidableBehaviour.h"


EnemyCollidableBehaviour::EnemyCollidableBehaviour()
{
}

void EnemyCollidableBehaviour::Hit(CollidableBehaviour* cb){
	if (cb){
		switch (cb->GetActor()->GetType()){
		case EntityType::BULLET:
			ent->SetHealth(ent->GetHealth() - cb->GetActor()->GetDamage());
			SoundBank::GetInstance()->Play(SoundEffectType::CORRECT);
			break;
		default:
			break;
		}
	}
}
CollidableBehaviour* EnemyCollidableBehaviour::EmptyClone(){
	return new EnemyCollidableBehaviour;
}

EnemyCollidableBehaviour::~EnemyCollidableBehaviour()
{
}
