#pragma once
#include "Sprite.h"
class ShotgunSprite :
	public Sprite
{
public:
	ShotgunSprite(SDL_Renderer* _renderer);
	~ShotgunSprite();


protected:
	virtual void SetAnimations() override;
};

