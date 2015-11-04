#pragma once
#include "DrawableBehaviour.h"
class GroundDrawableBehaviour :
	public DrawableBehaviour
{
public:
	GroundDrawableBehaviour(SDL_Renderer* renderer, int screenwidth, int screenheight);
	~GroundDrawableBehaviour();

	GroundDrawableBehaviour* EmptyClone() override;

	void Draw() override;
	void SetSprites(vector<SDL_Rect> sdl_sprites) override;
	bool LoadMedia() override;

private:
	SDL_Rect sprites;
};

