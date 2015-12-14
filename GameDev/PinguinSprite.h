#pragma once
#include "Sprite.h"
class PinguinSprite : public Sprite
{
public:
	PinguinSprite(SDL_Renderer* _renderer);
	~PinguinSprite();

protected:
	virtual void SetAnimations() override;
};

