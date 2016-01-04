#pragma once
#include "Sprite.h"
class TankSprite :
	public Sprite
{
public:
	TankSprite(SDL_Renderer* _renderer);
	~TankSprite();

protected:
	virtual void SetAnimations() override;
};

