#pragma once
#include "DrawableBehaviour.h"
class StaticDrawableBehaviour :
	public DrawableBehaviour
{
public:
	StaticDrawableBehaviour(SDL_Renderer* renderer, Sprite* _sprite, int screenwidth, int screenheight);
	~StaticDrawableBehaviour();

	StaticDrawableBehaviour* EmptyClone() override;

	void Draw(bool cycle) override;
};