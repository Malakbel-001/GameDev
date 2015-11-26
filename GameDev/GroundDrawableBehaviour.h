#pragma once
#include "DrawableBehaviour.h"


class GroundDrawableBehaviour :
	public DrawableBehaviour
{
public:
	GroundDrawableBehaviour(SDL_Renderer* renderer, Sprite* _sprite, int screenwidth, int screenheight);
	~GroundDrawableBehaviour();

	GroundDrawableBehaviour* EmptyClone() override;

	void Draw() override;

private:
	SDL_Rect sprites;
};

