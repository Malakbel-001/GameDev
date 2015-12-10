#include "FramesPerSecond.h"

FramesPerSecond::FramesPerSecond(SDL_Renderer* _renderer) {
	renderer = _renderer;

	screenWidth = new int;
	screenHeight = new int;
	SDL_GetWindowSize(SDL_GetWindowFromID(1), screenWidth, screenHeight);
	
	fpsCounter = 0;
	currentFPS = 0;
	fpsFont = Utilities::GetInstance()->SetFont("Resources/fonts/manaspc.ttf", 30);
}

FramesPerSecond::~FramesPerSecond() {
	this->Cleanup();
}

void FramesPerSecond::Cleanup() {
	//fonts
	TTF_CloseFont(fpsFont);

	delete screenWidth;
	delete screenHeight;
	screenWidth = nullptr;
	screenHeight = nullptr;
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
	std::cout << "FPS: " << currentFPS << std::endl;

	Utilities::GetInstance()->DrawTextHelper(renderer, fpsFont, std::to_string(currentFPS), *screenWidth - 50, 10, Utilities::GetInstance()->Color(255, 100, 100, 255));
}