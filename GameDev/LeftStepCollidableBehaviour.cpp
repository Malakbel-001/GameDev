#include "LeftStepCollidableBehaviour.h"

LeftStepCollidableBehaviour::LeftStepCollidableBehaviour()
{
	steps = 0;
}


LeftStepCollidableBehaviour::~LeftStepCollidableBehaviour()
{
}

void LeftStepCollidableBehaviour::Hit(CollidableBehaviour* cb){
	steps++;
	//if (cb){
	//	switch (cb->GetActor()->GetType()){
	//	default:
	//		//TODO different sound
	//		ent->SetNumFootContacts(ent->GetNumFootContacts() + 1);
	//		break;
	//	}
	//}
	//else{
	//	ent->SetNumFootContacts(ent->GetNumFootContacts() + 1);

	//}
}

void LeftStepCollidableBehaviour::Unhit(CollidableBehaviour* cb){
	steps--;
	if (steps == 0)
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
	}
	/*if (cb){
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
	}*/
}
CollidableBehaviour* LeftStepCollidableBehaviour::EmptyClone(){
	return new LeftStepCollidableBehaviour();
}

void LeftStepCollidableBehaviour::SetLeft(bool l)
{
	left = l;
}