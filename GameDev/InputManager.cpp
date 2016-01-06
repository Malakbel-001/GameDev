#include "InputManager.h"

InputManager::InputManager()
{
	input = new std::unordered_map<SDL_Keycode, bool>();

	konamiCheats = std::vector<SDL_Keycode>();
	konamiCheats.push_back(SDLK_UP);
	konamiCheats.push_back(SDLK_UP);
	konamiCheats.push_back(SDLK_DOWN);
	konamiCheats.push_back(SDLK_DOWN);
	konamiCheats.push_back(SDLK_LEFT);
	konamiCheats.push_back(SDLK_RIGHT);
	konamiCheats.push_back(SDLK_LEFT);
	konamiCheats.push_back(SDLK_RIGHT);
	konamiCheats.push_back(SDLK_b);
	konamiCheats.push_back(SDLK_a);

	gta2Cheats = std::vector<SDL_Keycode>();
	gta2Cheats.push_back(SDLK_g);
	gta2Cheats.push_back(SDLK_o);
	gta2Cheats.push_back(SDLK_u);
	gta2Cheats.push_back(SDLK_r);
	gta2Cheats.push_back(SDLK_a);
	gta2Cheats.push_back(SDLK_n);
	gta2Cheats.push_back(SDLK_g);
	gta2Cheats.push_back(SDLK_a);
	
	cheatConverter = std::unordered_map<SDL_Keycode, SDL_Keycode>();
	cheatConverter.insert({ SDLK_y, SDLK_F13 });
	cheatConverter.insert({ SDLK_u, SDLK_F14 });
	cheatConverter.insert({ SDLK_i, SDLK_F15 });
	cheatConverter.insert({ SDLK_o, SDLK_F16 });
	cheatConverter.insert({ SDLK_p, SDLK_F17 });
	cheatConverter.insert({ SDLK_l, SDLK_F18 });


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

	if (cheating){
		auto cheatKey = cheatConverter.find(key);
		if (cheatKey != cheatConverter.end()){
			//SDL_Keycode cheatKey = cheatConverter.at(key);
			
			if (input->find(cheatKey->second) == input->end())
			{
				input->insert({ cheatKey->second, true });
			}
			else
			{
				if (input->find(cheatKey->second)->second){
					input->at(cheatKey->second) = false;
				}
				else{
					input->at(cheatKey->second) = true;
				}
			
			}

		}		

	}
	if (konamiCheats.at(konamCheatsCounter) == key){
		konamCheatsCounter++;
		gta2CheatsCounter = 0;
		if (konamCheatsCounter > konamiCheats.size() - 1){
			cheating = true;
			printf("Cheats enabled");
			konamCheatsCounter = 0;
		}
	}
	else if (gta2Cheats.at(gta2CheatsCounter) == key){
		gta2CheatsCounter++;
		konamCheatsCounter = 0;
		if (gta2CheatsCounter > gta2Cheats.size() - 1){
			cheating = true;
			printf("Cheats enabled");
			gta2CheatsCounter = 0;
		}
	}
	else{
		gta2CheatsCounter = 0;
		konamCheatsCounter = 0;
	}


	if (input->find(key) == input->end())	
	{
		SDL_Keycode inputkey = RemapKey(key);
		input->insert({ inputkey, true });
	}
	else
	{
		SDL_Keycode inputkey = RemapKey(key);
		input->at(inputkey) = true;
	}

}

void InputManager::ResetKeyInput(SDL_Keycode key)
{

	if (cheating){
		if (key == SDLK_l){
			
				//SDL_Keycode cheatKey = cheatConverter.at(key);

			if (input->find(SDLK_F18) == input->end())
				{
					input->insert({ SDLK_F18, true });
				}
				else
				{
					
					input->at(SDLK_F18) = false;
				

				}

		}
	}
	
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