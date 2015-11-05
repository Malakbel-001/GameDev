#pragma once
#include "DrawableBehaviour.h"


class GroundObstacleDrawableBehavior : 
	public DrawableBehaviour
{
public:
	GroundObstacleDrawableBehavior(SDL_Renderer* renderer, int screenwidth, int screenheight);
	~GroundObstacleDrawableBehavior();

	GroundObstacleDrawableBehavior* EmptyClone() override;

	void Draw() override;
	void SetSprites(vector<SDL_Rect> sdl_sprites) override;
	bool LoadMedia() override;

private:
	SDL_Rect sprites;
	
};

