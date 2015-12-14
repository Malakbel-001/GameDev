#include "PlantSprite.h"


PlantSprite::PlantSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = 8;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	DYING_ANIMATION_FRAMES = 3;
	SetAnimations();
}


PlantSprite::~PlantSprite()
{
}

void PlantSprite::SetAnimations()
{
	idleSprites->resize(IDLE_ANIMATION_FRAMES);

	idleSprites->at(0).x = 6;
	idleSprites->at(0).y = 395;
	idleSprites->at(0).w = 45;
	idleSprites->at(0).h = 50;

	idleSprites->at(1).x = idleSprites->at(0).x + idleSprites->at(0).w;
	idleSprites->at(1).y = 395;
	idleSprites->at(1).w = 45;
	idleSprites->at(1).h = 50;

	idleSprites->at(2).x = idleSprites->at(1).x + idleSprites->at(1).w + 10;
	idleSprites->at(2).y = 395;
	idleSprites->at(2).w = 45;
	idleSprites->at(2).h = 50;

	idleSprites->at(3).x = idleSprites->at(2).x + idleSprites->at(2).w + 10;
	idleSprites->at(3).y = 395;
	idleSprites->at(3).w = 45;
	idleSprites->at(3).h = 50;

	idleSprites->at(4).x = idleSprites->at(3).x + idleSprites->at(3).w + 10;
	idleSprites->at(4).y = 395;
	idleSprites->at(4).w = 45;
	idleSprites->at(4).h = 50;

	idleSprites->at(5).x = idleSprites->at(4).x + idleSprites->at(4).w + 10;
	idleSprites->at(5).y = 395;
	idleSprites->at(5).w = 45;
	idleSprites->at(5).h = 50;

	idleSprites->at(6).x = idleSprites->at(5).x + idleSprites->at(5).w + 10;
	idleSprites->at(6).y = 395;
	idleSprites->at(6).w = 45;
	idleSprites->at(6).h = 50;

	idleSprites->at(7).x = idleSprites->at(6).x + idleSprites->at(6).w + 10;
	idleSprites->at(7).y = 395;
	idleSprites->at(7).w = 45;
	idleSprites->at(7).h = 50;
}