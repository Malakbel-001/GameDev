#include "ApcSprite.h"


ApcSprite::ApcSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = -1;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	DYING_ANIMATION_FRAMES = -1;
	SetAnimations();
}


ApcSprite::~ApcSprite()
{
}
void ApcSprite::SetAnimations()
{
	defaultSprite.x = 12;
	defaultSprite.y = 22;
	defaultSprite.w = 143;
	defaultSprite.h = 128;
}