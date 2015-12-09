#include "FramesPerSecond.h"

FramesPerSecond::FramesPerSecond() {
	fpsCounter = 0;
	currentFPS = 0;
}

FramesPerSecond::~FramesPerSecond() {
	this->Cleanup();
}

void FramesPerSecond::Cleanup() {
	//fonts
	TTF_CloseFont(fpsFont);
}

void FramesPerSecond::SetFPSFont(char* path, int ptsize) {
	if (TTF_Init() == -1) //initialize TTF
		std::cout << " Failed to initialize TTF : " << TTF_GetError() << std::endl;

	fpsFont = TTF_OpenFont("Resources/fonts/manaspc.ttf", 12);

	if (fpsFont == nullptr)
		std::cout << " Failed to load font : " << TTF_GetError() << std::endl;
}

void FramesPerSecond::UpdateCount() {
	fpsCounter++;

	if (ticks + 1000 < SDL_GetTicks()) { //not sure if this is correct
		currentFPS = fpsCounter;
		ticks = SDL_GetTicks();
		fpsCounter = 0;
	}
}

void FramesPerSecond::DrawFPS() {
	//draw
	std::cout << "FPS: " << fpsCounter << std::endl;

	
}