#pragma once
#include "Sprite.h"
class GunSprite :
	public Sprite
{
public:
	GunSprite(SDL_Renderer* _renderer);
	~GunSprite();


protected:
	virtual void SetAnimations() override;
};

