#include "BehaviourFactory.h"


BehaviourFactory::BehaviourFactory(SDL_Renderer* sdl_renderer, int screenwidth, int screenheight)
{
	renderer = sdl_renderer;
	screenWidth = screenwidth;
	screenHeight = screenheight;

	registery = std::unordered_map<EntityType, DrawableBehaviour*>{
			{ EntityType::PLAYER, new PlayerDrawableBehaviour(renderer, screenWidth, screenHeight) },
			{ EntityType::GROUND, new GroundDrawableBehaviour(renderer, screenWidth, screenHeight) }
	};
}

SDL_Renderer* BehaviourFactory::GetRenderer(){
	return renderer;
}


BehaviourFactory::~BehaviourFactory()
{
	registery.clear();
}

DrawableBehaviour* BehaviourFactory::CreateDrawableBehaviour(EntityType type)
{
	DrawableBehaviour* behaviour = registery.at(type)->EmptyClone();
	
	return behaviour;
}