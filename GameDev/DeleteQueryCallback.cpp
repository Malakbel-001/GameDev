#include "DeleteQueryCallback.h"

DeleteQueryCallback::DeleteQueryCallback() {

}

DeleteQueryCallback::~DeleteQueryCallback() {
	//no pointers
}

bool DeleteQueryCallback::ReportFixture(b2Fixture* fixture) {
	foundBodies.push_back(fixture->GetBody());
	return true; //keep going to find all fixtures in the query area
}