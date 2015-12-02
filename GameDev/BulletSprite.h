#pragma once
#include "Sprite.h"
class BulletSprite :
	public Sprite
{
public:
	BulletSprite(SDL_Renderer* _renderer);
	~BulletSprite();

protected:
	virtual void SetAnimations() override;

};

