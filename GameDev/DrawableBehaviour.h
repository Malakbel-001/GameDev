#pragma once
#include "SDL.h"
#include "Behaviour.h"
class DrawableBehaviour :
	public Behaviour
{
public:
	DrawableBehaviour();
	virtual ~DrawableBehaviour();

	DrawableBehaviour* EmptyClone();

	void Draw(SDL_Renderer* renderer);
};

