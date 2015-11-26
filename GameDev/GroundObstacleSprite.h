#pragma once
#include "Sprite.h"
class GroundObstacleSprite :
	public Sprite
{
public:
	GroundObstacleSprite(SDL_Renderer* _renderer);
	~GroundObstacleSprite();

protected:
	virtual void SetAnimations() override;
};

