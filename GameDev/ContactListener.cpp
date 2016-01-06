#include "ContactListener.h"
#include "CollidableBehaviour.h"

ContactListener::ContactListener()
{
}


ContactListener::~ContactListener()
{
}
void ContactListener::BeginContact(b2Contact* contact){
	
	void* bodyUserData = contact->GetFixtureA()->GetUserData();
	CollidableBehaviour* beh = nullptr;
	CollidableBehaviour* beh2 = nullptr;
	
	if (bodyUserData){
		 beh = static_cast<CollidableBehaviour*>(bodyUserData);		
	}


	void* bodyUserData2 = contact->GetFixtureB()->GetUserData();
	if (bodyUserData2){
		beh2 = static_cast<CollidableBehaviour*>(bodyUserData2);
		beh2->Hit(beh);
	}
	if (bodyUserData){
		beh->Hit(beh2);
	}


}
void ContactListener::EndContact(b2Contact* contact){
	void* bodyUserData = contact->GetFixtureA()->GetUserData();
	CollidableBehaviour* beh = nullptr;
	CollidableBehaviour* beh2 = nullptr;
	if (bodyUserData){
		beh = static_cast<CollidableBehaviour*>(bodyUserData);
	}


	void* bodyUserData2 = contact->GetFixtureB()->GetUserData();
	if (bodyUserData2){
		beh2 = static_cast<CollidableBehaviour*>(bodyUserData2);
		beh2->Unhit(beh);
	}
	if (bodyUserData){
		beh->Unhit(beh2);
	}
}