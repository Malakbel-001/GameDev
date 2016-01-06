#pragma once
#include <unordered_map>
#include <SDL.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include "Input.h"
class KeyMapping
{
public:
	KeyMapping();
	~KeyMapping();

	std::unordered_map <SDL_Keycode, SDL_Keycode>  GetKeyMap();

private:
	std::unordered_map <std::string, SDL_Keycode>  KeyCodeMap;
	const char* keyMapLoc = "Resources/settings/KeyMapping.txt";

};

