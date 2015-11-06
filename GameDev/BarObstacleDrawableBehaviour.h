#pragma once
#include "DrawableBehaviour.h"
#include "camera.h"


class BarObstacleDrawableBehaviour :
	public DrawableBehaviour
{
public:
	BarObstacleDrawableBehaviour(SDL_Renderer* renderer, int screenwidth, int screenheight);
	~BarObstacleDrawableBehaviour();

	BarObstacleDrawableBehaviour* EmptyClone() override;

	void Draw() override;
	void SetSprites(vector<SDL_Rect> sdl_sprites) override;
	bool LoadMedia() override;

private:
	SDL_Rect sprites;
};


