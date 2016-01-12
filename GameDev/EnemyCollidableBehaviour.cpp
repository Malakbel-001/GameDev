#include "EnemyCollidableBehaviour.h"
#include "Apc.h"

EnemyCollidableBehaviour::EnemyCollidableBehaviour()
{
}

void EnemyCollidableBehaviour::Hit(CollidableBehaviour* cb){
	if (cb){
		switch (cb->GetActor()->GetType()){
		case EntityType::BULLET:
				ent->SetHealth(ent->GetHealth() - cb->GetActor()->GetDamage());

			//SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
			break;
		case EntityType::PLANT:
		{
			b2Vec2 vec = ent->GetBody()->GetLinearVelocity();
			if (vec.x >= 0)
			{
				vec.x = -vec.x;
			}
			else
			{
				vec.x = fabs(vec.x);
			}

			ent->GetBody()->SetLinearVelocity(vec);
			break;
		}

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
