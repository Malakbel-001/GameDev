#include "MechSprite.h"

MechSprite::MechSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = -1;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	DYING_ANIMATION_FRAMES = -1;
	SetAnimations();
}

MechSprite::~MechSprite()
{
}

void MechSprite::SetAnimations()
{	
	defaultSprite.x = 7;
	defaultSprite.y = 2;
	defaultSprite.w = 193;
	defaultSprite.h = 85;
}