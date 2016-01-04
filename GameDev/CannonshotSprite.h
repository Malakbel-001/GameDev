#pragma once
#include "Sprite.h"
class CannonshotSprite :
	public Sprite
{
public:
	CannonshotSprite(SDL_Renderer* _renderer);
	~CannonshotSprite();

protected:
	virtual void SetAnimations() override;

};

