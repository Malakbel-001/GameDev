#pragma once
#include "Sprite.h"
class HealthSprite :
	public Sprite
{
public:	
	HealthSprite(SDL_Renderer* _renderer);
	~HealthSprite();
protected:
	virtual void SetAnimations() override;
};

