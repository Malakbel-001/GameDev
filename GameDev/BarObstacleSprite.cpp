#include "BarObstacleSprite.h"


BarObstacleSprite::BarObstacleSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = -1;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	DYING_ANIMATION_FRAMES = -1;
}


BarObstacleSprite::~BarObstacleSprite()
{
}

void BarObstacleSprite::SetAnimations()
{
	defaultSprite.x = 514;
	defaultSprite.y = 527;
	defaultSprite.w = 256;
	defaultSprite.h = 10;
}