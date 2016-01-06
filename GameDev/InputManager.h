#pragma once
#include <SDL.h>
#include <unordered_map>
#include <vector>
#include "Input.h"
#include "KeyMapping.h"

class InputManager
{
	private:
		std::unordered_map<SDL_Keycode, bool>* input;

		std::unordered_map <SDL_Keycode, SDL_Keycode> remap;

		SDL_Event mouseEvent;
		SDL_Event TextInputEvent;

		std::vector<SDL_Keycode> konamiCheats;
		std::vector<SDL_Keycode> gta2Cheats;
		std::unordered_map<SDL_Keycode, SDL_Keycode> cheatConverter;
		int konamCheatsCounter = 0;
		int gta2CheatsCounter = 0;
		bool cheating = false;
		SDL_Keycode RemapKey(SDL_Keycode);
	public:
		InputManager();
		~InputManager();

		void SetKeyInput(SDL_Keycode key);
		void ResetKeyInput(SDL_Keycode key);
		std::unordered_map<SDL_Keycode, bool>* GetKeyInput();

		void SetMouseInput(SDL_Event _event);
		void SetMouseMotion(SDL_Event _event);
		SDL_Event GetMouseInput();
		void ResetMouseInput();

		void SetTextInput(SDL_Event _event);
		SDL_Event GetTextInput();
		void ResetTextInput();
};
