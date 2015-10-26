#include "DrawableContainer.h"


DrawableContainer::DrawableContainer()
{
}


DrawableContainer::~DrawableContainer()
{
}

void DrawableContainer::Add(DrawableBehaviour behaviour)
{
	behaviours.push_back(behaviour);
}

void DrawableContainer::Draw(SDL_Renderer* renderer)
{
	for each (DrawableBehaviour behaviour in behaviours)
	{
		behaviour.Draw(renderer);
	}
}