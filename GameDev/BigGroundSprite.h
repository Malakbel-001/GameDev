#pragma once
#include "Sprite.h"
class BigGroundSprite :
	public Sprite
{
public:
	BigGroundSprite(SDL_Renderer* _renderer);
	~BigGroundSprite();

protected:
	virtual void SetAnimations() override;
};

