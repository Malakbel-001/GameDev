#include "CollisionFilterContainer.h"

//Use CollisionType! For example:
//new CollisionFilterContainer(CollisionType::ALLY, CollisionType::OTHER | CollisionType::ENEMY));
//this means, the Entity would be CollisionType Ally and collides with OTHER and ENEMY
//this Entity would not Collide with anything that is NOT -> OTHER or ENEMY
//so this Entity would for example not collide with something that is ALLY or anything else for that matter
CollisionFilterContainer::CollisionFilterContainer(uint16 _categoryBits, uint16 _maskBits) {
	categoryBits = _categoryBits;
	maskBits = _maskBits;
}

CollisionFilterContainer::~CollisionFilterContainer() {
	//no pointers
}

uint16 CollisionFilterContainer::GetCategoryBits() {
	return categoryBits;
}

uint16 CollisionFilterContainer::GetMaskBits() {
	return maskBits;
}