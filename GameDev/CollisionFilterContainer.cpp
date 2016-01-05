#include "CollisionFilterContainer.h"

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