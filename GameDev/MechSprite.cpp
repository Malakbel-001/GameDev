#include "MechSprite.h"

MechSprite::MechSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = 7;
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
	idleSprites->resize(IDLE_ANIMATION_FRAMES);

	idleSprites->at(0).x = 8;
	idleSprites->at(0).y = 3;
	idleSprites->at(0).w = 178;
	idleSprites->at(0).h = 144;

	idleSprites->at(1).x = 1;
	idleSprites->at(1).y = 159;
	idleSprites->at(1).w = 178;
	idleSprites->at(1).h = 155;

	idleSprites->at(2).x = 192;
	idleSprites->at(2).y = 159;
	idleSprites->at(2).w = 178;
	idleSprites->at(2).h = 150;

	idleSprites->at(3).x = 382;
	idleSprites->at(3).y = 159;
	idleSprites->at(3).w = 178;
	idleSprites->at(3).h = 150;

	idleSprites->at(4).x = 1;
	idleSprites->at(4).y = 319;
	idleSprites->at(4).w = 178;
	idleSprites->at(4).h = 155;

	idleSprites->at(5).x = 191;
	idleSprites->at(5).y = 319;
	idleSprites->at(5).w = 178;
	idleSprites->at(5).h = 150;

	idleSprites->at(6).x = 381;
	idleSprites->at(6).y = 319;
	idleSprites->at(6).w = 178;
	idleSprites->at(6).h = 150;
}