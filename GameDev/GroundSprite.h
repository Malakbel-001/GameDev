#pragma once
#include "Sprite.h"
class GroundSprite :
	public Sprite
{
public:
	GroundSprite();
	~GroundSprite();

protected:
	virtual void SetAnimations() override;
};

