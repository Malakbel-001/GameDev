#include "BarObstacleSprite.h"


BarObstacleSprite::BarObstacleSprite(SDL_Renderer* _renderer) : Sprite(_renderer)
{
}


BarObstacleSprite::~BarObstacleSprite()
{
}

void BarObstacleSprite::SetAnimations()
{
	defaultSprite.x = 514;
	defaultSprite.y = 527;
	defaultSprite.w = 256;
	defaultSprite.h = 10;
}