#pragma once
#include "Sprite.h"
class PlantBossSprite :
	public Sprite
{
public:
	PlantBossSprite(SDL_Renderer* _renderer);
	~PlantBossSprite();

protected:
	virtual void SetAnimations() override;
};

