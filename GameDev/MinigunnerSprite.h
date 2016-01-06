#pragma once
#include "Sprite.h"
class MinigunnerSprite :
	public Sprite
{
public:
	MinigunnerSprite(SDL_Renderer* _renderer);
	~MinigunnerSprite();

protected:
	virtual void SetAnimations() override;
};

