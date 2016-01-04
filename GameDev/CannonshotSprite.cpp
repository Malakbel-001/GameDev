#include "CannonshotSprite.h"


CannonshotSprite::CannonshotSprite(SDL_Renderer* _renderer) :Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = -1;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	SetAnimations();
}


CannonshotSprite::~CannonshotSprite()
{
}

void CannonshotSprite::SetAnimations()
{
	defaultSprite.x = 376;
	defaultSprite.y = 316;
	defaultSprite.w = 39;
	defaultSprite.h = 12;
}