#pragma once
#include "Sprite.h"
class smallDesertSprite :
	public Sprite
{
public:
	smallDesertSprite(SDL_Renderer* _renderer);
	~smallDesertSprite();

protected:
	virtual void SetAnimations() override;
};

