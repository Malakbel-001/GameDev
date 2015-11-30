#include "TreeSprite.h"


TreeSprite::TreeSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = -1;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	DYING_ANIMATION_FRAMES = -1;
	SetAnimations();
}


TreeSprite::~TreeSprite()
{
}

void TreeSprite::SetAnimations(){
	defaultSprite.x = 265;
	defaultSprite.y = 175;
	defaultSprite.w = 468;
	defaultSprite.h = 650;
}
