#pragma once
#include "Sprite.h"
class DesertGroundSprite :
	public Sprite
{
public:
	DesertGroundSprite(SDL_Renderer* _renderer);
	~DesertGroundSprite();

protected:
	virtual void SetAnimations() override;
};

