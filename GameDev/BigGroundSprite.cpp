#include "BigGroundSprite.h"


BigGroundSprite::BigGroundSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = -1;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	DYING_ANIMATION_FRAMES = -1;

	yOffSet = -20;

	SetAnimations();
}

BigGroundSprite::~BigGroundSprite()
{
}

void BigGroundSprite::SetAnimations()
{
	defaultSprite.x = 0;
	defaultSprite.y = 397;
	defaultSprite.w = 256;
	defaultSprite.h = 256;
}