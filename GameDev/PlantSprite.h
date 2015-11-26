#pragma once
#include "Sprite.h"
class PlantSprite :
	public Sprite
{
public:
	PlantSprite(SDL_Renderer* _renderer);
	~PlantSprite();

protected:
	virtual void SetAnimations() override;
};

