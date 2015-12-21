#include "InputManager.h"

InputManager::InputManager()
{
	input = new std::unordered_map<SDL_Keycode, bool>();
	KeyMapping k = KeyMapping();
	remap = k.GetKeyMap();
	
}

InputManager::~InputManager()
{
	delete input;
}
SDL_Keycode InputManager::RemapKey(SDL_Keycode key){
	
	auto it = remap.find(key);
	if (it != remap.end()){
		return it->second;
	}
	return key;
}
void InputManager::SetKeyInput(SDL_Keycode key)
{
	SDL_Keycode inputkey = RemapKey(key);
	
	
	
	if (input->find(inputkey) == input->end())
	{
		input->insert({ inputkey, true });
	}
	else
	{
		input->at(inputkey) = true;
	}
}

void InputManager::ResetKeyInput(SDL_Keycode key)
{
	SDL_Keycode inputkey = RemapKey(key);
	if (!(input->find(inputkey) == input->end()))
	{
		input->at(inputkey) = false;
	}
}

void InputManager::SetMouseInput(SDL_Event _event)
{
	mouseEvent = _event;
}

void InputManager::SetMouseMotion(SDL_Event _event)
{
	mouseEvent = _event;
}

void InputManager::ResetMouseInput()
{
	mouseEvent = SDL_Event();
}

void InputManager::SetTextInput(SDL_Event _event)
{
	TextInputEvent = _event;
}
void InputManager::ResetTextInput(){
	TextInputEvent = SDL_Event();
}

SDL_Event InputManager::GetTextInput(){
	return TextInputEvent;
}


SDL_Event InputManager::GetMouseInput()
{
	return mouseEvent;
}

std::unordered_map<SDL_Keycode, bool>* InputManager::GetKeyInput()
{
	return input;
}