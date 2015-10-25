#pragma once
#include "DrawableBehaviour.h"
#include "Entity.h"

class BehaviourFactory
{
public:
	BehaviourFactory();
	~BehaviourFactory();

	DrawableBehaviour CreateDrawableBehaviour(Entity entity, SDL_Renderer* sdl_renderer);
};

