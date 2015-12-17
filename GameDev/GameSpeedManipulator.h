#pragma once
#include <unordered_map>
#include <SDL.h> //TODO get this outta here probs
#include "SDL_ttf.h" //maybe this 1, 2
#include "Utitilies.h"

class GameSpeedManipulator {
	private:
		SDL_Renderer* renderer;
		TTF_Font* font;

		bool run;
		int* screenWidth;
		int* screenHeight;

		Uint32 lockButtonTicks;

		float manipulator = 1; //initialized
		float limitCounter = 0;
		const float limit = 2; //limit

		void ToggleDraw();

	public:
		GameSpeedManipulator(SDL_Renderer* renderer);
		~GameSpeedManipulator();
		void Cleanup();
		void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
		float GetManipulator();
		void Draw();

};