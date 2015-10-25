#include "DrawableContainer.h"
#include "SDL.h";

DrawableContainer::DrawableContainer(SDL_Renderer* sdl_renderer)
{
	renderer = sdl_renderer;
}


DrawableContainer::~DrawableContainer()
{
}

void DrawableContainer::Add(DrawableBehaviour behaviour)
{
	behaviours.push_back(behaviour);
}

SDL_Renderer* DrawableContainer::GetRenderer()
{
	return renderer;
}

void DrawableContainer::ClearScreen()
{
	//Clear screen
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
}
