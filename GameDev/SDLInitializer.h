#pragma once
#include <string>
#include <SDL.h>
#include <iostream>

class SDLInitializer
{
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;

	public:
		SDLInitializer();
		void Init(const char* title, int width, int height, bool fullscreen);
		void ClearScreen();
		void DrawTexture(SDL_Texture* texture, const SDL_Rect* destRect, SDL_Rect* crop);
		void DrawScreen();

		void SetRenderDrawColor(int r, int g, int b);
		void ResetRenderDrawColor();

		SDL_Renderer* GetRenderer();
		SDL_Window* GetWindow();
	
		void RenderToScreen(int x, int y, SDL_Texture* texture, SDL_Rect* clip);

		virtual ~SDLInitializer();
};
