#pragma once
#include "SDL_ttf.h"
#include <iostream>

class FramesPerSecond {
	private:
		int fpsCounter;
		TTF_Font* fpsFont;

		void SetFPSFont(char* path, int ptsize);
		void DrawFPS();

	public:
		FramesPerSecond();
		~FramesPerSecond();
		void UpdateCount();

};