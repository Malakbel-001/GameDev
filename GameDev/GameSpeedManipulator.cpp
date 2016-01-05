#include "GameSpeedManipulator.h"

GameSpeedManipulator::GameSpeedManipulator(SDL_Renderer* _renderer) {
	this->renderer = _renderer;

	screenWidth = new int;
	screenHeight = new int;
	SDL_GetWindowSize(SDL_GetWindowFromID(1), screenWidth, screenHeight);

	run = false;
	font = Utilities::SetFont("Resources/fonts/manaspc.ttf", 30);
	lockButtonTicks = SDL_GetTicks();
}

GameSpeedManipulator::~GameSpeedManipulator() {
	this->Cleanup();
}

void GameSpeedManipulator::Cleanup() {
	//fonts
	TTF_CloseFont(font);

	delete screenWidth;
	delete screenHeight;
	screenWidth = nullptr;
	screenHeight = nullptr;
}

void GameSpeedManipulator::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events) {
	for (auto it = _events->begin(); it != _events->end(); ++it){
		if (it->second)	{
			switch (it->first) {
				case SDLK_PAGEUP:
					// times 1
					if (lockButtonTicks + 100 < SDL_GetTicks()) {
						if (limitCounter < limit) {
							manipulator *= 2;
							limitCounter++;
							lockButtonTicks = SDL_GetTicks();
						}
					}
					
					break;
				case SDLK_PAGEDOWN:
					// times -1
					if (lockButtonTicks + 100 < SDL_GetTicks()) {
						if (limitCounter > -limit) {
							manipulator *= 0.5f;
							limitCounter--;
							lockButtonTicks = SDL_GetTicks();
						}
					}
					break;
				case SDLK_HOME:
					// reset
					if (lockButtonTicks + 100 < SDL_GetTicks()) {
						manipulator = 1;
						limitCounter = 0;
						lockButtonTicks = SDL_GetTicks();
					}
					break;
				case SDLK_COMMA:
					// toggle draw manipulator amount on/off
					run = Utilities::ToggleDraw(lockButtonTicks, screenWidth, screenHeight, run);
					lockButtonTicks = SDL_GetTicks();
					break;
			}
		}
	}
}

void GameSpeedManipulator::Draw() {
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << manipulator;
	std::string display = stream.str();

	if (run) {
		Utilities::DrawTextHelper(renderer, font, display + "X", 100, 10, Utilities::GetColor(255, 0, 0, 255), *screenWidth);
	}
}

float GameSpeedManipulator::GetManipulator() {
	return manipulator;
}