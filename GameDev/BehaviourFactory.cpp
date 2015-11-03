#include "BehaviourFactory.h"


BehaviourFactory::BehaviourFactory()
{
	registery = std::unordered_map<BehaviourType, DrawableBehaviour>{
			{ BehaviourType::DRAWABLEBEHAVIOUR, DrawableBehaviour() },
		{BehaviourType::GROUNDDRAWABLEBEHAVIOUR, GroundDrawableBehaviour() }
			
	};
}


BehaviourFactory::~BehaviourFactory()
{
}

DrawableBehaviour* BehaviourFactory::CreateDrawableBehaviour(BehaviourType type, Entity* ent)
{
	DrawableBehaviour* behaviour = registery.at(type).EmptyClone();
	behaviour->body = ent->body;

	return behaviour;
}