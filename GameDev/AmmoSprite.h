#pragma once
#include "Sprite.h"
class AmmoSprite :
	public Sprite
{
public:
	AmmoSprite(SDL_Renderer* _renderer);
	~AmmoSprite();

protected:
	virtual void SetAnimations() override;

};

