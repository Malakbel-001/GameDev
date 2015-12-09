#pragma once
#include "SDL_ttf.h"
#include <iostream>

class FramesPerSecond {
	private:
		float ticks;
		int fpsCounter;
		int currentFPS;
		TTF_Font* fpsFont;

		void SetFPSFont(char* path, int ptsize);

	public:
		FramesPerSecond();
		~FramesPerSecond();
		void Cleanup();
		void UpdateCount();
		void DrawFPS();
		
};