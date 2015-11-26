#pragma once
#include "Sprite.h"
class PlayerSprite :
	public Sprite
{
public:
	PlayerSprite(SDL_Renderer* _renderer);
	~PlayerSprite();

protected:
	virtual void SetAnimations() override;
};

