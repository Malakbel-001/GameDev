#pragma once
#include "Sprite.h"
class BarObstacleSprite :
	public Sprite
{
public:
	BarObstacleSprite(SDL_Renderer* _renderer);
	~BarObstacleSprite();

protected:
	virtual void SetAnimations() override;
};

