#include "DesertGroundSprite.h"


DesertGroundSprite::DesertGroundSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = -1;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	DYING_ANIMATION_FRAMES = -1;

	yOffSet = -20;

	SetAnimations();
}


DesertGroundSprite::~DesertGroundSprite()
{
}

void DesertGroundSprite::SetAnimations()
{
	defaultSprite.x = 3;
	defaultSprite.y = 612;
	defaultSprite.w = 1075;
	defaultSprite.h = 51;
}