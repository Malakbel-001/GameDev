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
	ClearScreen(renderer);
	for each (DrawableBehaviour behaviour in behaviours)
	{
		behaviour.Draw(renderer, spriteSheetTexture);
	}
	UpdateScreen(renderer);
}

void DrawableContainer::ClearScreen(SDL_Renderer* renderer)
{
	//Update screen
	SDL_RenderPresent(renderer);
}

void DrawableContainer::UpdateScreen(SDL_Renderer* renderer)
{
	//Clear screen
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
}