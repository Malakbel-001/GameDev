#include "MechSprite.h"

MechSprite::MechSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = 1;
	WALK_ANIMATION_FRAMES = 7;
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

	idleSprites->at(0).x = 374;
	idleSprites->at(0).y = 3;
	idleSprites->at(0).w = 180;
	idleSprites->at(0).h = 144;

	walkSprites->resize(WALK_ANIMATION_FRAMES);

	walkSprites->at(0).x = 374;
	walkSprites->at(0).y = 3;
	walkSprites->at(0).w = 180;
	walkSprites->at(0).h = 144;

	walkSprites->at(1).x = 387;
	walkSprites->at(1).y = 318;
	walkSprites->at(1).w = 180;
	walkSprites->at(1).h = 155;

	walkSprites->at(2).x = 1;
	walkSprites->at(2).y = 318;
	walkSprites->at(2).w = 180;
	walkSprites->at(2).h = 152;

	walkSprites->at(3).x = 382;
	walkSprites->at(3).y = 159;
	walkSprites->at(3).w = 178;
	walkSprites->at(3).h = 150;

	walkSprites->at(4).x = 381;
	walkSprites->at(4).y = 159;
	walkSprites->at(4).w = 179;
	walkSprites->at(4).h = 155;

	walkSprites->at(5).x = 190;
	walkSprites->at(5).y = 158;
	walkSprites->at(5).w = 181;
	walkSprites->at(5).h = 151;

	walkSprites->at(6).x = 0;
	walkSprites->at(6).y = 158;
	walkSprites->at(6).w = 181;
	walkSprites->at(6).h = 151;
}