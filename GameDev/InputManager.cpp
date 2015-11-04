#include "InputManager.h"


InputManager::InputManager()
{
	input = new std::unordered_map<SDL_Keycode, bool>();
}


InputManager::~InputManager()
{
}

void InputManager::SetInput(SDL_Keycode key)
{
	if (input->find(key) == input->end())
	{
		input->insert({ key, true });
	}
	else{
		input->at(key) = true;
	}
}

void InputManager::ResetInput(SDL_Keycode key)
{
	if (!(input->find(key) == input->end()))
	{
		input->at(key) = false;
	}

}

std::unordered_map<SDL_Keycode, bool>* InputManager::GetInput(){
	return input;
}