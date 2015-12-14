#pragma once
#include "Sprite.h"
class AcornSprite :
	public Sprite
{
public:
	AcornSprite(SDL_Renderer* _renderer);
	~AcornSprite();

protected:
	virtual void SetAnimations() override;
};

