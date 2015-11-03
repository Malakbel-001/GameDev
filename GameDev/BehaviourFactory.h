#pragma once
#include <unordered_map>
#include "BehaviourType.h"
#include "DrawableBehaviour.h"
#include "MoveableBehaviour.h"
#include "CollidableBehaviour.h"
#include "Entity.h"
#include "GroundDrawableBehaviour.h"

class BehaviourFactory
{
public:
	BehaviourFactory();
	~BehaviourFactory();

	DrawableBehaviour* CreateDrawableBehaviour(BehaviourType type,Entity* ent);
	
private:
	std::unordered_map<BehaviourType, DrawableBehaviour> registery;
};

