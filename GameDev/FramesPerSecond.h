#pragma once
#include "SDL_ttf.h"
#include <iostream>
#include "Utitilies.h"
#include "SoundBank.h"

class FramesPerSecond {
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

		void ToggleFps();

	public:
		FramesPerSecond(SDL_Renderer* renderer);
		~FramesPerSecond();
		void Cleanup();
		void UpdateCount();
		void DrawFPS();
		void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);

};