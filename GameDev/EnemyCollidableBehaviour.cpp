#include "EnemyCollidableBehaviour.h"


EnemyCollidableBehaviour::EnemyCollidableBehaviour()
{
}

void EnemyCollidableBehaviour::Hit(CollidableBehaviour* cb){
	if (cb){
		switch (cb->GetActor()->GetType()){
		case EntityType::BULLET:
			ent->SetHealt(ent->GetHealt() - cb->GetActor()->GetDamage());
			SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
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
