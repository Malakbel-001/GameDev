#include "GunSprite.h"


GunSprite::GunSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{

	IDLE_ANIMATION_FRAMES = -1;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	xOffSet = 10;
	yOffSet = 15;

	SetAnimations();
}


void GunSprite::SetAnimations()
{
	defaultSprite.x = 3;
	defaultSprite.y = 5;
	defaultSprite.w = 24;
	defaultSprite.h = 14;
}



GunSprite::~GunSprite()
{
}
