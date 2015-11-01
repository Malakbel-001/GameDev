#pragma once
#include <unordered_map>
#include "BehaviourType.h"
#include "DrawableBehaviour.h"
#include "MoveableBehaviour.h"
#include "CollidableBehaviour.h"

class BehaviourFactory
{
public:
	BehaviourFactory();
	~BehaviourFactory();

	DrawableBehaviour* CreateDrawableBehaviour(BehaviourType type);
	
private:
	std::unordered_map<BehaviourType, DrawableBehaviour> registery;
};

