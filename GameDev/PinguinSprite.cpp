#include "PinguinSprite.h"


PinguinSprite::PinguinSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = 8;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	DYING_ANIMATION_FRAMES = 3;
	SetAnimations();
}


PinguinSprite::~PinguinSprite()
{
}
void PinguinSprite::SetAnimations()
{

	idleSprites->resize(IDLE_ANIMATION_FRAMES);

	idleSprites->at(0).x = 12;
	idleSprites->at(0).y = 131;
	idleSprites->at(0).w = 24;
	idleSprites->at(0).h = 36;

	idleSprites->at(1).x = 45;
	idleSprites->at(1).y = 131;
	idleSprites->at(1).w = 24;
	idleSprites->at(1).h = 36;

	idleSprites->at(2).x = 81;
	idleSprites->at(2).y = 131;
	idleSprites->at(2).w = 24;
	idleSprites->at(2).h = 36;

	idleSprites->at(3).x = 116;
	idleSprites->at(3).y = 131;
	idleSprites->at(3).w = 24;
	idleSprites->at(3).h = 36;

	idleSprites->at(4).x = 151;
	idleSprites->at(4).y = 131;
	idleSprites->at(4).w = 24;
	idleSprites->at(4).h = 36;

	idleSprites->at(5).x = 186;
	idleSprites->at(5).y = 131;
	idleSprites->at(5).w = 24;
	idleSprites->at(5).h = 36;

	idleSprites->at(6).x = 221;
	idleSprites->at(6).y = 131;
	idleSprites->at(6).w = 24;
	idleSprites->at(6).h = 36;

	idleSprites->at(7).x = 257;
	idleSprites->at(7).y = 131;
	idleSprites->at(7).w = 24;
	idleSprites->at(7).h = 36;
}

