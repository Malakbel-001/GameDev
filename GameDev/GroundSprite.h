#pragma once
#include "Sprite.h"
class GroundSprite :
	public Sprite
{
public:
	GroundSprite(SDL_Renderer* _renderer);
	~GroundSprite();

protected:
	virtual void SetAnimations() override;
};

