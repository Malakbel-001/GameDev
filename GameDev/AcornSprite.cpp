#include "AcornSprite.h"


AcornSprite::AcornSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = 4;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	DYING_ANIMATION_FRAMES = -1;
	SetAnimations();
}


AcornSprite::~AcornSprite()
{
}

void AcornSprite::SetAnimations()
{
	idleSprites->resize(IDLE_ANIMATION_FRAMES);

	idleSprites->at(0).x = 510;
	idleSprites->at(0).y = 815;
	idleSprites->at(0).w = 20;
	idleSprites->at(0).h = 20;

	idleSprites->at(1).x = 534;
	idleSprites->at(1).y = 815;
	idleSprites->at(1).w = 20;
	idleSprites->at(1).h = 20;

	idleSprites->at(2).x = 556;
	idleSprites->at(2).y = 815;
	idleSprites->at(2).w = 20;
	idleSprites->at(2).h = 20;

	idleSprites->at(3).x = 580;
	idleSprites->at(3).y = 815;
	idleSprites->at(3).w = 20;
	idleSprites->at(3).h = 20;
}