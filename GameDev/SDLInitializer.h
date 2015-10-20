#pragma once
#include <string>
#include <SDL.h>
class SDLInitializer
{
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;

	public:
		SDLInitializer();
		void init(const char* title, int width, int height, bool fullscreen);
		void clearScreen();
		void drawTexture(SDL_Texture* texture, const SDL_Rect* destRect, SDL_Rect* crop);
		void drawScreen();

		void setRenderDrawColor(int r, int g, int b);
		void resetRenderDrawColor();

		SDL_Renderer* getRenderer();
		SDL_Window* getWindow();
	
		void RenderToScreen(int x, int y, SDL_Texture* texture, SDL_Rect* clip);

		virtual ~SDLInitializer();
};
