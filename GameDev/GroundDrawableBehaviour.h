#pragma once
#include "DrawableBehaviour.h"
#include <iostream>

class GroundDrawableBehaviour :
	public DrawableBehaviour
{
public:
	GroundDrawableBehaviour();
	~GroundDrawableBehaviour();

	 DrawableBehaviour* EmptyClone();
	 void Draw(SDL_Renderer* renderer);
	 bool LoadMedia(SDL_Renderer* renderer);
};

