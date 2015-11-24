#pragma once
#include "DrawableBehaviour.h"
#include "camera.h"


class BarObstacleDrawableBehaviour :
	public DrawableBehaviour
{
public:
	BarObstacleDrawableBehaviour(SDL_Renderer* renderer, Sprite* _sprite, int screenwidth, int screenheight);
	~BarObstacleDrawableBehaviour();

	BarObstacleDrawableBehaviour* EmptyClone() override;

	void Draw() override;

private:
	SDL_Rect sprites;
};


