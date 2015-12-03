#include "SnowmanSprite.h"


SnowmanSprite::SnowmanSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = 14;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	DYING_ANIMATION_FRAMES = -1;
	SetAnimations();
}


SnowmanSprite::~SnowmanSprite()
{
}

void SnowmanSprite::SetAnimations()
{
	idleSprites->resize(IDLE_ANIMATION_FRAMES);
	spriteYOffset->resize(IDLE_ANIMATION_FRAMES);
	spriteXOffset->resize(IDLE_ANIMATION_FRAMES);

	idleSprites->at(0).x = 392;
	idleSprites->at(0).y = 499;
	idleSprites->at(0).w = 33;
	idleSprites->at(0).h = 42;
	spriteXOffset->at(0) = -1;

	idleSprites->at(1).x = 428;
	idleSprites->at(1).y = 499;
	idleSprites->at(1).w = 34;
	idleSprites->at(1).h = 42;
	spriteXOffset->at(1) = 0;

	idleSprites->at(2).x = 465;
	idleSprites->at(2).y = 499;
	idleSprites->at(2).w = 34;
	idleSprites->at(2).h = 42;
	spriteXOffset->at(2)  = 0;

	idleSprites->at(3).x = 502;
	idleSprites->at(3).y = 499;
	idleSprites->at(3).w = 33;
	idleSprites->at(3).h = 42;
	spriteXOffset->at(3) = 0;

	idleSprites->at(4).x = 538;
	idleSprites->at(4).y = 498;
	idleSprites->at(4).w = 34;
	idleSprites->at(4).h = 43;
	spriteYOffset->at(4) = 1;
	spriteXOffset->at(4) = 0;

	idleSprites->at(5).x = 575;
	idleSprites->at(5).y = 484;
	idleSprites->at(5).w = 69;
	idleSprites->at(5).h = 57;
	spriteYOffset->at(5) = 15;
	spriteXOffset->at(5) = 35;

	idleSprites->at(6).x = 647;
	idleSprites->at(6).y = 506;
	idleSprites->at(6).w = 68;
	idleSprites->at(6).h = 35;
	spriteYOffset->at(6) = -7;
	spriteXOffset->at(6) = 34;
	
	idleSprites->at(7).x = 392;
	idleSprites->at(7).y = 582;
	idleSprites->at(7).w = 68;
	idleSprites->at(7).h = 34;
	spriteYOffset->at(7) = -8;
	spriteXOffset->at(7) = 34;

	idleSprites->at(8).x = 463;
	idleSprites->at(8).y = 581;
	idleSprites->at(8).w = 68;
	idleSprites->at(8).h = 35;
	spriteYOffset->at(8) = -7;
	spriteXOffset->at(8) = 34;

	idleSprites->at(9).x = 534;
	idleSprites->at(9).y = 578;
	idleSprites->at(9).w = 67;
	idleSprites->at(9).h = 38;
	spriteYOffset->at(9) = -4;
	spriteXOffset->at(9) = 33;

	idleSprites->at(10).x = 604;
	idleSprites->at(10).y = 575;
	idleSprites->at(10).w = 58;
	idleSprites->at(10).h = 41;
	spriteYOffset->at(10) = -1;
	spriteXOffset->at(10) = 24;

	idleSprites->at(11).x = 665;
	idleSprites->at(11).y = 544;
	idleSprites->at(11).w = 36;
	idleSprites->at(11).h = 72;
	spriteYOffset->at(11) = 30;
	spriteXOffset->at(11) = 2;

	idleSprites->at(12).x = 701;
	idleSprites->at(12).y = 565;
	idleSprites->at(12).w = 40;
	idleSprites->at(12).h = 51;
	spriteYOffset->at(12) = 9;
	spriteXOffset->at(12) = 6;

	idleSprites->at(13).x = 744;
	idleSprites->at(13).y = 573;
	idleSprites->at(13).w = 35;
	idleSprites->at(13).h = 43;
	spriteYOffset->at(13) = 2;
	spriteXOffset->at(13) = 1;
	/*
	idleSprites->at(14).x = 351;
	idleSprites->at(14).y = 91;
	idleSprites->at(14).w = 68;
	idleSprites->at(14).h = 93;

	idleSprites->at(15).x = 419;
	idleSprites->at(15).y = 91;
	idleSprites->at(15).w = 71;
	idleSprites->at(15).h = 93;

	idleSprites->at(16).x = 490;
	idleSprites->at(16).y = 91;
	idleSprites->at(16).w = 71;
	idleSprites->at(16).h = 93;

	idleSprites->at(17).x = 561;
	idleSprites->at(17).y = 91;
	idleSprites->at(17).w = 68;
	idleSprites->at(17).h = 93;

	idleSprites->at(18).x = 0;
	idleSprites->at(18).y = 193;
	idleSprites->at(18).w = 71;
	idleSprites->at(18).h = 82;

	idleSprites->at(19).x = 71;
	idleSprites->at(19).y = 193;
	idleSprites->at(19).w = 71;
	idleSprites->at(19).h = 82;

	idleSprites->at(20).x = 142;
	idleSprites->at(20).y = 193;
	idleSprites->at(20).w = 65;
	idleSprites->at(20).h = 82;

	idleSprites->at(21).x = 207;
	idleSprites->at(21).y = 193;
	idleSprites->at(21).w = 62;
	idleSprites->at(21).h = 82;

	idleSprites->at(22).x = 269;
	idleSprites->at(22).y = 193;
	idleSprites->at(22).w = 70;
	idleSprites->at(22).h = 82;

	idleSprites->at(23).x = 339;
	idleSprites->at(23).y = 193;
	idleSprites->at(23).w = 69;
	idleSprites->at(23).h = 82;

	idleSprites->at(24).x = 408;
	idleSprites->at(24).y = 193;
	idleSprites->at(24).w = 72;
	idleSprites->at(24).h = 82;
	*/
}
