#pragma once
#include "SDL_ttf.h"
#include <iostream>
#include "Utitilies.h"
#include "SoundBank.h"

class FramesPerSecond {
	private:
		SDL_Renderer* renderer;
		TTF_Font* fpsFont;

		int* screenWidth;
		int* screenHeight;

		float ticks;
		int fpsCounter;
		int currentFPS;

	public:
		FramesPerSecond(SDL_Renderer* renderer);
		~FramesPerSecond();
		void Cleanup();
		void UpdateCount();
		void DrawFPS();
		
};