#include "GroundObstacleSprite.h"


GroundObstacleSprite::GroundObstacleSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = -1;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	DYING_ANIMATION_FRAMES = -1;
}


GroundObstacleSprite::~GroundObstacleSprite()
{
}

void GroundObstacleSprite::SetAnimations()
{
	defaultSprite.x = 280;
	defaultSprite.y = 783;
	defaultSprite.w = 137;
	defaultSprite.h = 140;
}