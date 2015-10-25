#pragma once
#include "Vector"
#include "Container.h"
#include "DrawableBehaviour.h"

using namespace std;

class DrawableContainer :
	public Container
{
public:
	DrawableContainer(SDL_Renderer* renderer);
	virtual ~DrawableContainer();

	void Add(DrawableBehaviour behaviour);
	SDL_Renderer* GetRenderer();
	void ClearScreen();

private:
	vector<DrawableBehaviour> behaviours;
	SDL_Renderer* renderer;
};

