#pragma once
#include "Sprite.h"
class SnowmanSprite : public Sprite
{
public:
	SnowmanSprite(SDL_Renderer* _renderer);
	~SnowmanSprite();

protected:
	virtual void SetAnimations() override;
};

