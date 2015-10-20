#include "SDLInitializer.h"
#include <iostream>

SDLInitializer::SDLInitializer() { }

void SDLInitializer::init(const char* title, int width, int height, bool fullscreen)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow
	(
		title,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		fullscreen
	);

	// Set window icon
	/*SDL_Surface *surfice = IMG_Load("FilePath");
	SDL_SetWindowIcon(window, surfice);
	SDL_FreeSurface(surfice);*/

	renderer = SDL_CreateRenderer(window, -1, 0);
}

void SDLInitializer::setRenderDrawColor(int r, int g, int b)
{
	SDL_SetRenderDrawColor(this->getRenderer(), r, g, b, 255);
}

void SDLInitializer::resetRenderDrawColor()
{
	SDL_SetRenderDrawColor(this->getRenderer(), 0, 0, 0, 255);
}

void SDLInitializer::clearScreen()
{
	SDL_RenderClear(renderer);
}

void SDLInitializer::drawTexture(SDL_Texture* texture, const SDL_Rect* destRect, SDL_Rect* crop)
{
	SDL_RenderCopy(renderer, texture, crop, destRect);
}

void SDLInitializer::drawScreen()
{
	SDL_RenderPresent(renderer);
}

SDL_Renderer* SDLInitializer::getRenderer()
{
	return renderer;
}

SDL_Window* SDLInitializer::getWindow()
{
	return window;
}

void SDLInitializer::RenderToScreen(int x, int y, SDL_Texture* texture, SDL_Rect* clip)
{
	//Set rendering space and render to screen
	int width, height;
	SDL_QueryTexture(texture, NULL, NULL, &width, &height);
	SDL_Rect renderQuad = { x, y, width, height };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopy(getRenderer(), texture, clip, &renderQuad);
}

SDLInitializer::~SDLInitializer()
{
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
}