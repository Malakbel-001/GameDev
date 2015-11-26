#pragma once
#include "DrawableBehaviour.h"


class GroundObstacleDrawableBehavior : 
	public DrawableBehaviour
{
public:
	GroundObstacleDrawableBehavior(SDL_Renderer* renderer, Sprite* _sprite, int screenwidth, int screenheight);
	~GroundObstacleDrawableBehavior();

	GroundObstacleDrawableBehavior* EmptyClone() override;

	void Draw() override;

private:
	SDL_Rect sprites;
	
};

