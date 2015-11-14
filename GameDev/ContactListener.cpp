#include "ContactListener.h"
#include "CollidableBehaviour.h"

ContactListener::ContactListener()
{
}


ContactListener::~ContactListener()
{
}
void ContactListener::BeginContact(b2Contact* contact){
	
	void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
	if (bodyUserData){
		printf("f");
	}


	void* bodyUserData2 = contact->GetFixtureB()->GetBody()->GetUserData();
	if (bodyUserData2){
		printf("f");
	}
	if (bodyUserData && bodyUserData2){
		CollidableBehaviour* beh = static_cast<CollidableBehaviour*>(bodyUserData);
		CollidableBehaviour* beh2 = static_cast<CollidableBehaviour*>(bodyUserData2);

		beh->Hit(beh2->GetHitDmg());
		beh2->Hit(beh->GetHitDmg());
		
	}
}
void ContactListener::EndContact(b2Contact* contact){
	
}