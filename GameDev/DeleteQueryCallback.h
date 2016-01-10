#pragma once
#include "Box2D\Box2D.h" //fix errors, duuurp, theoretically not needed
#include <vector>

class DeleteQueryCallback : public b2QueryCallback {
	public:
		DeleteQueryCallback();
		~DeleteQueryCallback();

		std::vector<b2Body*> foundBodies;
		virtual bool ReportFixture(b2Fixture* fixture) override;
};