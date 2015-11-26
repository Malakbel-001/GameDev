#pragma once
#include "DrawableBehaviour.h"
class AnimatedDrawableBehaviour :
	public DrawableBehaviour
{
private:
	const int IDLE_ANIMATION_FRAMES = 8;
	const int WALK_ANIMATION_FRAMES = 7;
	vector<SDL_Rect> idleSprites;
	vector<SDL_Rect> walkSprites;

public:
	AnimatedDrawableBehaviour(SDL_Renderer* renderer, Sprite* _sprite, int screenwidth, int screenheight);
	~AnimatedDrawableBehaviour();

	AnimatedDrawableBehaviour* EmptyClone() override;

	void Draw() override;
};