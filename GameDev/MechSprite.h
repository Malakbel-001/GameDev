#pragma once
#include "Sprite.h"
class MechSprite :
	public Sprite
{
public:
	MechSprite(SDL_Renderer* _renderer);
	~MechSprite();

protected:
	virtual void SetAnimations() override;
};

