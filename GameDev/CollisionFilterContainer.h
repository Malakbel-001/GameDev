#pragma once
#include "Box2D\Box2D.h"

class CollisionFilterContainer {
	private:
		//this is the category a fixtureBody will belong 2
		uint16 categoryBits;

		//this is what the category can collide with
		uint16 maskBits;

	public:
		CollisionFilterContainer(uint16 _categoryBits, uint16 _maskBits);
		~CollisionFilterContainer();

		uint16 GetCategoryBits();
		uint16 GetMaskBits();
};