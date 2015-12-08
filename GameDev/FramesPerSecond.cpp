#include "FramesPerSecond.h"

FramesPerSecond::FramesPerSecond() {

}

FramesPerSecond::~FramesPerSecond() {

}

void FramesPerSecond::SetFPSFont(char* path, int ptsize) {
	if (TTF_Init() == -1) //initialize TTF
		std::cout << " Failed to initialize TTF : " << TTF_GetError() << std::endl;

	fpsFont = TTF_OpenFont("Resources/fonts/manaspc.ttf", 12);

	if (fpsFont == nullptr)
		std::cout << " Failed to load font : " << TTF_GetError() << std::endl;
}

void FramesPerSecond::DrawFPS() {

}