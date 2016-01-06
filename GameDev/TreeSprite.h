#pragma once
#include "Sprite.h"
class TreeSprite : public Sprite
{
public:
	TreeSprite(SDL_Renderer* _renderer);
	~TreeSprite();

protected:
	virtual void SetAnimations() override;
};
