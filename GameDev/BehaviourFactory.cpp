#include "BehaviourFactory.h"
#include "PlayerDrawableBehaviour.h"


BehaviourFactory::BehaviourFactory()
{
}


BehaviourFactory::~BehaviourFactory()
{
}

DrawableBehaviour BehaviourFactory::CreateDrawableBehaviour(Entity entity, SDL_Renderer* sdl_renderer)
{
	return new PlayerDrawableBehaviour(sdl_renderer);
}
