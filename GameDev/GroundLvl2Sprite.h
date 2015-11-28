#pragma once
#include "Sprite.h"
class GroundLvl2Sprite : public Sprite
{
public:
	GroundLvl2Sprite(SDL_Renderer* _renderer);
	~GroundLvl2Sprite();

protected:
	virtual void SetAnimations() override;
};

