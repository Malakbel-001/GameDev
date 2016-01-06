#include "TankSprite.h"


TankSprite::TankSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = 4;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	DYING_ANIMATION_FRAMES = 3;
	SetAnimations();
}


TankSprite::~TankSprite()
{
}

void TankSprite::SetAnimations()
{
	idleSprites->resize(IDLE_ANIMATION_FRAMES);

	idleSprites->at(0).x = 196;
	idleSprites->at(0).y = 389;
	idleSprites->at(0).w = 55;
	idleSprites->at(0).h = 65;

	idleSprites->at(1).x = 259;
	idleSprites->at(1).y = 388;
	idleSprites->at(1).w = 55;
	idleSprites->at(1).h = 65;

	idleSprites->at(2).x = 318;
	idleSprites->at(2).y = 388;
	idleSprites->at(2).w = 55;
	idleSprites->at(2).h = 65;

	idleSprites->at(3).x = 378;
	idleSprites->at(3).y = 387;
	idleSprites->at(3).w = 55;
	idleSprites->at(3).h = 65;
}