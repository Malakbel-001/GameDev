#pragma once
#include <SDL.h>
#include <unordered_map>
class InputManager
{
public:
	InputManager();
	~InputManager();

	void SetKeyInput(SDL_Keycode key);
	void ResetKeyInput(SDL_Keycode key);
	std::unordered_map<SDL_Keycode, bool>* GetKeyInput();

	void SetMouseInput(SDL_Event _event);
	SDL_Event GetMouseInput();
private:
	std::unordered_map<SDL_Keycode, bool>* input;
	SDL_Event mouseEvent;
};

