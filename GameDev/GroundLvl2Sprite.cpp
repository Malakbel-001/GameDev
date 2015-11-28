#include "GroundLvl2Sprite.h"


GroundLvl2Sprite::GroundLvl2Sprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = -1;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	DYING_ANIMATION_FRAMES = -1;
	SetAnimations();
}


GroundLvl2Sprite::~GroundLvl2Sprite()
{
}

void GroundLvl2Sprite::SetAnimations()
{
	defaultSprite.x = 514;
	defaultSprite.y = 397;
	defaultSprite.w = 256;
	defaultSprite.h = 140;
}
