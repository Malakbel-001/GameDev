#include "smallDesertSprite.h"


smallDesertSprite::smallDesertSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = -1;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	DYING_ANIMATION_FRAMES = -1;

	yOffSet = -20;

	SetAnimations();
}


smallDesertSprite::~smallDesertSprite()
{
}

void smallDesertSprite::SetAnimations()
{
	defaultSprite.x = 580;
	defaultSprite.y = 730;
	defaultSprite.w = 135;
	defaultSprite.h = 50;
}