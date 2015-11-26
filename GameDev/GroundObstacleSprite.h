#pragma once
#include "Sprite.h"
class GroundObstacleSprite :
	public Sprite
{
public:
	GroundObstacleSprite();
	~GroundObstacleSprite();

protected:
	virtual void SetAnimations() override;
};

