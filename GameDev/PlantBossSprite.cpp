#include "PlantBossSprite.h"


PlantBossSprite::PlantBossSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
	IDLE_ANIMATION_FRAMES = 13;
	WALK_ANIMATION_FRAMES = -1;
	JUMP_ANIMATION_FRAMES = -1;
	SHOOT_ANIMATION_FRAMES = -1;
	DYING_ANIMATION_FRAMES = 3;
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

	idleSprites->at(1).x = 145;
	idleSprites->at(1).y = 65;
	idleSprites->at(1).w = 115;
	idleSprites->at(1).h = 100;

	idleSprites->at(2).x = 292;
	idleSprites->at(2).y = 65;
	idleSprites->at(2).w = 115;
	idleSprites->at(2).h = 100;

	idleSprites->at(3).x = 425;
	idleSprites->at(3).y = 65;
	idleSprites->at(3).w = 115;
	idleSprites->at(3).h = 100;

	idleSprites->at(4).x = 555;
	idleSprites->at(4).y = 62;
	idleSprites->at(4).w = 110;
	idleSprites->at(4).h = 103;

	idleSprites->at(5).x = 670;
	idleSprites->at(5).y = 62;
	idleSprites->at(5).w = 110;
	idleSprites->at(5).h = 103;

	idleSprites->at(6).x = 905;
	idleSprites->at(6).y = 47;
	idleSprites->at(6).w = 104;
	idleSprites->at(6).h = 116;

	idleSprites->at(7).x = 670;
	idleSprites->at(7).y = 62;
	idleSprites->at(7).w = 110;
	idleSprites->at(7).h = 103;

	idleSprites->at(8).x = 555;
	idleSprites->at(8).y = 62;
	idleSprites->at(8).w = 110;
	idleSprites->at(8).h = 103;

	idleSprites->at(9).x = 425;
	idleSprites->at(9).y = 65;
	idleSprites->at(9).w = 115;
	idleSprites->at(9).h = 100;

	idleSprites->at(10).x = 292;
	idleSprites->at(10).y = 65;
	idleSprites->at(10).w = 115;
	idleSprites->at(10).h = 100;

	idleSprites->at(11).x = 145;
	idleSprites->at(11).y = 65;
	idleSprites->at(11).w = 115;
	idleSprites->at(11).h = 100;

	idleSprites->at(12).x = 12;
	idleSprites->at(12).y = 70;
	idleSprites->at(12).w = 115;
	idleSprites->at(12).h = 100;

	dyingSprites->resize(DYING_ANIMATION_FRAMES);

	dyingSprites->at(0).x = 673;
	dyingSprites->at(0).y = 813;
	dyingSprites->at(0).w = 105;
	dyingSprites->at(0).h = 136;

	dyingSprites->at(1).x = 805;
	dyingSprites->at(1).y = 832;
	dyingSprites->at(1).w = 117;
	dyingSprites->at(1).h = 107;

	dyingSprites->at(2).x = 953;
	dyingSprites->at(2).y = 843;
	dyingSprites->at(2).w = 112;
	dyingSprites->at(2).h = 95;
}