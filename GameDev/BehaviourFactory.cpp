#include "BehaviourFactory.h"


BehaviourFactory::BehaviourFactory()
{
	registery = std::unordered_map<BehaviourType, DrawableBehaviour>{
		{ BehaviourType::DRAWABLEBEHAVIOUR, DrawableBehaviour() }
	};
}


BehaviourFactory::~BehaviourFactory()
{
}

DrawableBehaviour* BehaviourFactory::CreateDrawableBehaviour(BehaviourType type)
{
	DrawableBehaviour* behaviour = registery.at(type).EmptyClone();
	return behaviour;
}