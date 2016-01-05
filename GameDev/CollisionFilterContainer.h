#pragma once
#include "Box2D\Box2D.h"
#include "CollisionType.h"

//currently not in use because in hindsight, it wasn't needed (at first I thought I needed it), 
//but still, this class might be very useful for future use when it comes to CollisionFiltering,
//using this is best along the lines with a collisionFilterRegistery in the EntityFactory
//if needed in the future
class CollisionFilterContainer {
	private:
		//this is what your Entity is qualified as (look for example in CollisionEntityType)
		uint16 categoryBits;

		//this is what your Entity can Collide with
		uint16 maskBits;

	public:
		CollisionFilterContainer(uint16 _categoryBits, uint16 _maskBits);
		~CollisionFilterContainer();

		//Getters
		uint16 GetCategoryBits();
		uint16 GetMaskBits();

		//No setters at the moment, probably not needed
};