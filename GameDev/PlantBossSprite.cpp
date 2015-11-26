#include "PlantBossSprite.h"


PlantBossSprite::PlantBossSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = 8;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	SetAnimations();
}


PlantBossSprite::~PlantBossSprite()
{
}

void PlantBossSprite::SetAnimations()
{
	idleSprites->resize(IDLE_ANIMATION_FRAMES);

	idleSprites->at(0).x = 12;
	idleSprites->at(0).y = 70;
	idleSprites->at(0).w = 115;
	idleSprites->at(0).h = 100;
}