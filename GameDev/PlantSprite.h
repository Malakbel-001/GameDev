#pragma once
#include "Sprite.h"
class PlantSprite :
	public Sprite
{
public:
	PlantSprite();
	~PlantSprite();

protected:
	virtual void SetAnimations() override;
};

