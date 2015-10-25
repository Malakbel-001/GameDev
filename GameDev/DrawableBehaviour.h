#pragma once
#include "SDL.h"
#include "Behaviour.h"
class DrawableBehaviour :
	public Behaviour
{
public:
	DrawableBehaviour(SDL_Renderer* sdl_renderer);
	virtual ~DrawableBehaviour();	
protected:
	SDL_Renderer* renderer;
};

