#pragma once
#include "SDL_ttf.h"
#include <iostream>
#include "Utitilies.h"
#include "SoundBank.h"

class FPS {
	private:
		SDL_Renderer* renderer;
		TTF_Font* fpsFont;

		bool run;
		int* screenWidth;
		int* screenHeight;

		Uint32 timerTicks;
		Uint32 lockButtonTicks;
		int fpsCounter;
		int currentFPS;

	public:
		FPS(SDL_Renderer* renderer);
		~FPS();
		void Cleanup();
		void UpdateCount();
		void Draw();
		void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);

};