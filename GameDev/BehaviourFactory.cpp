#include "BehaviourFactory.h"


BehaviourFactory::BehaviourFactory(SDL_Renderer* sdl_renderer, int screenwidth, int screenheight)
{
	renderer = sdl_renderer;
	screenWidth = screenwidth;
	screenHeight = screenheight;

	registery = std::unordered_map<BehaviourType, DrawableBehaviour*>{
		{ BehaviourType::PLAYERDRAWABLEBEHAVIOUR, new PlayerDrawableBehaviour(renderer, screenWidth, screenHeight) },
		{ BehaviourType::GROUNDDRAWABLEBEHAVIOUR, new GroundDrawableBehaviour(renderer, screenWidth, screenHeight) }
	};
}


BehaviourFactory::~BehaviourFactory()
{
	registery.clear();
}

DrawableBehaviour* BehaviourFactory::CreateDrawableBehaviour(BehaviourType type)
{
	DrawableBehaviour* behaviour = registery.at(type)->EmptyClone();
	return behaviour;
}