#include "DrawableContainer.h"


DrawableContainer::DrawableContainer()
{


	behaviours = vector<DrawableBehaviour*>();

}


DrawableContainer::~DrawableContainer()
{
}

void DrawableContainer::Add(DrawableBehaviour* behaviour)
{
	behaviours.push_back(behaviour);
}

void DrawableContainer::Draw(SDL_Renderer* renderer)
{
	for each (DrawableBehaviour* behaviour in behaviours)
	{
		behaviour->Draw(renderer);
	}
}

void DrawableContainer::ClearScreen(SDL_Renderer* renderer)
{
	//Clear screen
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);	
}

void DrawableContainer::UpdateScreen(SDL_Renderer* renderer)
{
	//Update screen
	SDL_RenderPresent(renderer);
}