#pragma once
#include "Sprite.h"
class ApcSprite :
	public Sprite
{
public:
	ApcSprite(SDL_Renderer* _renderer);
	~ApcSprite();

protected:
	virtual void SetAnimations() override;
};
