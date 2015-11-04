#pragma once
#include <SDL.h>
#include <unordered_map>
class InputManager
{
public:
	InputManager();
	~InputManager();

	void SetInput(SDL_Keycode key);
	void ResetInput(SDL_Keycode key);

	std::unordered_map<SDL_Keycode, bool>* GetInput();
private:
	std::unordered_map<SDL_Keycode, bool>* input;
};

