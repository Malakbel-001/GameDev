#include "BulletSprite.h"


BulletSprite::BulletSprite(SDL_Renderer* _renderer) :Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = -1;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	SetAnimations();
}


BulletSprite::~BulletSprite()
{
}

void BulletSprite::SetAnimations()
{
	defaultSprite.x = 0;
	defaultSprite.y = 0;
	defaultSprite.w = 10;
	defaultSprite.h = 10;
}