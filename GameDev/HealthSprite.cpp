#include "HealthSprite.h"

	

HealthSprite::HealthSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = -1;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	SetAnimations();
}


HealthSprite::~HealthSprite()
{
}

void HealthSprite::SetAnimations()
{
	defaultSprite.x = 1;
	defaultSprite.y = 1;
	defaultSprite.w = 10;
	defaultSprite.h = 10;
}