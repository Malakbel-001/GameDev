#include "MinigunnerSprite.h"


MinigunnerSprite::MinigunnerSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = -1;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	DYING_ANIMATION_FRAMES = -1;

	yOffSet = 20;

	SetAnimations();
}


MinigunnerSprite::~MinigunnerSprite()
{
}

void MinigunnerSprite::SetAnimations()
{
	defaultSprite.x = 153;
	defaultSprite.y = 177;
	defaultSprite.w = 63;
	defaultSprite.h = 42;
}