#include "PlayerSprite.h"


PlayerSprite::PlayerSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = 3;
	WALK_ANIMATION_FRAMES = 7;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	DYING_ANIMATION_FRAMES = -1;
	SetAnimations();
}


PlayerSprite::~PlayerSprite()
{
}

void PlayerSprite::SetAnimations()
{
	idleSprites->resize(IDLE_ANIMATION_FRAMES);

	idleSprites->at(0).x = 4;
	idleSprites->at(0).y = 0;
	idleSprites->at(0).w = 30;
	idleSprites->at(0).h = 40;

	idleSprites->at(1).x = idleSprites->at(0).x + idleSprites->at(0).w;
	idleSprites->at(1).y = 0;
	idleSprites->at(1).w = 30;
	idleSprites->at(1).h = 40;

	idleSprites->at(2).x = idleSprites->at(1).x + idleSprites->at(1).w;
	idleSprites->at(2).y = 0;
	idleSprites->at(2).w = 30;
	idleSprites->at(2).h = 40;

	walkSprites->resize(WALK_ANIMATION_FRAMES);

	walkSprites->at(0).x = 107 + 30 + 28 + 3;
	walkSprites->at(0).y = 1;
	walkSprites->at(0).w = 32;
	walkSprites->at(0).h = 40;

	walkSprites->at(1).x = walkSprites->at(0).x + walkSprites->at(0).w + 1;
	walkSprites->at(1).y = 1;
	walkSprites->at(1).w = 32;
	walkSprites->at(1).h = 41;

	walkSprites->at(2).x = walkSprites->at(1).x + walkSprites->at(1).w + 2;
	walkSprites->at(2).y = 1;
	walkSprites->at(2).w = 27;
	walkSprites->at(2).h = 41;

	walkSprites->at(3).x = walkSprites->at(2).x + walkSprites->at(2).w + 4;
	walkSprites->at(3).y = 1;
	walkSprites->at(3).w = 29;
	walkSprites->at(3).h = 40;

	walkSprites->at(4).x = walkSprites->at(3).x + walkSprites->at(3).w + 3;
	walkSprites->at(4).y = 1;
	walkSprites->at(4).w = 32;
	walkSprites->at(4).h = 40;

	walkSprites->at(5).x = walkSprites->at(4).x + walkSprites->at(4).w + 0;
	walkSprites->at(5).y = 1;
	walkSprites->at(5).w = 36;
	walkSprites->at(5).h = 37;

	walkSprites->at(6).x = walkSprites->at(5).x + walkSprites->at(5).w + 0;
	walkSprites->at(6).y = 1;
	walkSprites->at(6).w = 31;
	walkSprites->at(6).h = 40;
}