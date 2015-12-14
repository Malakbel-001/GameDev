#include "SnowBossSprite.h"

SnowBossSprite::SnowBossSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = 1;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	SetAnimations();
}

SnowBossSprite::~SnowBossSprite()
{
}

void SnowBossSprite::SetAnimations(){
	defaultSprite.x = 450;
	defaultSprite.y = 216;
	defaultSprite.w = 122;
	defaultSprite.h = 120;
}
