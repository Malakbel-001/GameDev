#include "SDLInitializer.h"

SDLInitializer::SDLInitializer() {}

void SDLInitializer::Init(const char* title, int width, int height, bool fullscreen)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow
		(
		title,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		false
		);

	// Open Audio & Start SDL_Mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048 < 0))
	{
		std::cout << "Error: " << Mix_GetError() << std::endl;
	}

	// Set amount of SoundMixer Sound(Effect/)Chunk Channels to 100, temporarily.
	// Later this will most likely be changed to a dynamic amount using SoundBank and a cleanup loop every ?? seconds/updates
	// It's probably not a good idea to change the size 1000 times a second though.
	Mix_AllocateChannels(100); //Temporarily Hardcoded 100 Channels available.

	// Set window icon
	/*SDL_Surface *surfice = IMG_Load("FilePath");
	SDL_SetWindowIcon(window, surfice);
	SDL_FreeSurface(surfice);*/

	renderer = SDL_CreateRenderer(window, -1, 0);
}

void SDLInitializer::SetRenderDrawColor(int r, int g, int b)
{
	SDL_SetRenderDrawColor(this->GetRenderer(), r, g, b, 255);
}

void SDLInitializer::ResetRenderDrawColor()
{
	SDL_SetRenderDrawColor(this->GetRenderer(), 0, 0, 0, 255);
}

void SDLInitializer::ClearScreen()
{
	SDL_RenderClear(renderer);
}

void SDLInitializer::DrawTexture(SDL_Texture* texture, const SDL_Rect* destRect, SDL_Rect* crop)
{
	SDL_RenderCopy(renderer, texture, crop, destRect);
}

void SDLInitializer::DrawScreen()
{
	SDL_RenderPresent(renderer);
}

SDL_Renderer* SDLInitializer::GetRenderer()
{
	return renderer;
}

SDL_Window* SDLInitializer::GetWindow()
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
	SDL_RenderCopy(GetRenderer(), texture, clip, &renderQuad);
}

SDLInitializer::~SDLInitializer()
{
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
}