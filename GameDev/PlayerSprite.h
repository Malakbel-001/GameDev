#pragma once
#include "Sprite.h"
class PlayerSprite :
	public Sprite
{
public:
	PlayerSprite();
	~PlayerSprite();

protected:
	virtual void SetAnimations() override;
};

