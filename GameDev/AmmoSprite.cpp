#include "AmmoSprite.h"


AmmoSprite::AmmoSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = -1;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	SetAnimations();
}


AmmoSprite::~AmmoSprite()
{
}




void AmmoSprite::SetAnimations()
{
	defaultSprite.x = 1;
	defaultSprite.y = 5;
	defaultSprite.w = 29;
	defaultSprite.h = 17;
}