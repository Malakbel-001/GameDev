#include "GroundSprite.h"


GroundSprite::GroundSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = -1;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	DYING_ANIMATION_FRAMES = -1;
	SetAnimations();
}


GroundSprite::~GroundSprite()
{
}

void GroundSprite::SetAnimations()
{
	defaultSprite.x = 514;
	defaultSprite.y = 397;
	defaultSprite.w = 256;
	defaultSprite.h = 140;
}