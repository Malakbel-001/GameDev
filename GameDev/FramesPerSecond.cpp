#include "FramesPerSecond.h"

FramesPerSecond::FramesPerSecond(SDL_Renderer* _renderer) {
	renderer = _renderer;

	screenWidth = new int;
	screenHeight = new int;
	SDL_GetWindowSize(SDL_GetWindowFromID(1), screenWidth, screenHeight);
	
	run = false;
	fpsCounter = 0;
	currentFPS = 0;
	fpsFont = Utilities::SetFont("Resources/fonts/manaspc.ttf", 30);
	timerTicks = SDL_GetTicks();
	lockButtonTicks = SDL_GetTicks();
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

	if (timerTicks + 1000 < SDL_GetTicks()) { //not sure if this is correct
		currentFPS = fpsCounter;
		timerTicks = SDL_GetTicks();
		fpsCounter = 0;
	}
}

void FramesPerSecond::DrawFPS() {
	if (run) {
		Utilities::DrawTextHelper(renderer, fpsFont, std::to_string(currentFPS), *screenWidth - 50, 10, Utilities::GetColor(255, 0, 0, 255));
	}
}

void FramesPerSecond::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events) {
	for (auto it = _events->begin(); it != _events->end(); ++it){
		if (it->second)
		{
			switch (it->first)
			{
			case SDLK_m:
				ToggleFps();
				break;
			}
		}
	}
}

void FramesPerSecond::ToggleFps() {
	if (lockButtonTicks + 100 < SDL_GetTicks()) {
		run = !run; //toggle boolean

		if (run) {
			SDL_GetWindowSize(SDL_GetWindowFromID(1), screenWidth, screenHeight);
		}

		lockButtonTicks = SDL_GetTicks(); //make sure the button isn't being immediately pressed afterwards
	}
}