#pragma once
#include "Sprite.h"
class BarObstacleSprite :
	public Sprite
{
public:
	BarObstacleSprite();
	~BarObstacleSprite();

protected:
	virtual void SetAnimations() override;
};

