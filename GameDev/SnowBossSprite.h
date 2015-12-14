#pragma once
#include "Sprite.h"
class SnowBossSprite: public Sprite
{
public:
	SnowBossSprite(SDL_Renderer* _renderer);
	~SnowBossSprite();
protected:
	virtual void SetAnimations() override;
};

