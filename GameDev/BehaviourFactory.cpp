#include "BehaviourFactory.h"


BehaviourFactory::BehaviourFactory()
{
	registery = std::unordered_map<BehaviourType, Behaviour>{
		{ BehaviourType::BEHAVIOUR, Behaviour() },
		{ BehaviourType::DRAWABLEBEHAVIOUR, DrawableBehaviour() },
		{ BehaviourType::MOVEABLEBEHAVIOUR, MoveableBehaviour() },
		{ BehaviourType::COLLIDABLEBEHAVIOUR, CollidableBehaviour() }
	};
}


BehaviourFactory::~BehaviourFactory()
{
}

Behaviour* BehaviourFactory::CreateDrawableBehaviour(BehaviourType type)
{
	Behaviour* behaviour = registery.at(type).EmptyClone();
	return behaviour;
}