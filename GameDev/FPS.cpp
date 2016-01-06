#include "FPS.h"

FPS::FPS(SDL_Renderer* _renderer) {
	this->renderer = _renderer;

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

FPS::~FPS() {
	this->Cleanup();
}

void FPS::Cleanup() {
	//fonts
	TTF_CloseFont(fpsFont);

	delete screenWidth;
	delete screenHeight;
	screenWidth = nullptr;
	screenHeight = nullptr;
}

//UpdateCount and every second, set the currentFPS for that second
void FPS::UpdateCount() {
	fpsCounter++;

	if (timerTicks + 1000 < SDL_GetTicks()) {
		currentFPS = fpsCounter;
		timerTicks = SDL_GetTicks();
		fpsCounter = 0;
	}
}

void FPS::Draw() {
	if (run) {
		Utilities::DrawTextHelper(renderer, fpsFont, std::to_string(currentFPS), 20, 10, Utilities::GetColor(255, 0, 0, 255), *screenWidth);
	}
}

void FPS::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events) {
	for (auto it = _events->begin(); it != _events->end(); ++it) {
		if (it->second)	{
			if (it->first == SDLK_PERIOD) {
				run = Utilities::ToggleDraw(lockButtonTicks, screenWidth, screenHeight, run);
				lockButtonTicks = SDL_GetTicks();
			}
		}
	}
}