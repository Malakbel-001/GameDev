#include "HealthCollidableBehaviour.h"
#include "Actor.h"

HealthCollidableBehaviour::HealthCollidableBehaviour()
{

}
void HealthCollidableBehaviour::Hit(CollidableBehaviour* cb){
	if (cb){
		switch (cb->GetActor()->GetType()){
		case EntityType::PLAYER:
			ent->SetHealt(0);		
			break;
		default:
			break;
		}
	}
}
CollidableBehaviour* HealthCollidableBehaviour::EmptyClone(){
	return new HealthCollidableBehaviour;
}


HealthCollidableBehaviour::~HealthCollidableBehaviour()
{
}
