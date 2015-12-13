#include "KeyMapping.h"

KeyMapping::KeyMapping()
{
	
	KeyCodeMap = std::unordered_map < std::string, SDL_Keycode > {
			{"a", SDLK_a},
			{ "b", SDLK_b },
			{ "c", SDLK_c },
			{ "d", SDLK_d },
			{ "e", SDLK_e },
			{ "f", SDLK_f },
			{ "g", SDLK_g },
			{ "h", SDLK_h },
			{ "i", SDLK_i },
			{ "j", SDLK_j }, 
			{ "k", SDLK_k },
			{ "l", SDLK_l },
			{ "m", SDLK_m },
			{ "o", SDLK_o },
			{ "p", SDLK_p },
			{ "q", SDLK_q },
			{ "r", SDLK_r },
			{ "s", SDLK_s },
			{ "t", SDLK_t },
			{ "u", SDLK_u },
			{ "v", SDLK_v },
			{ "w", SDLK_w },
			{ "x", SDLK_x },
			{ "y", SDLK_y },
			{ "z", SDLK_z },
			{ "esc", SDLK_ESCAPE },
			{ "up", SDLK_UP },
			{ "down", SDLK_DOWN },
			{ "left", SDLK_LEFT },
			{ "right", SDLK_RIGHT },
			{ "1", SDLK_1 },
			{ "2", SDLK_2 },
			{ "3", SDLK_3 },
			{ "4", SDLK_4 },
			{ "5", SDLK_5 },
			{ "6", SDLK_6 },
			{ "7", SDLK_7 },
			{ "8", SDLK_8 },
			{ "9", SDLK_9 },
			{ "0", SDLK_0 },
			{ "space", SDLK_SPACE },
			{ "enter", SDLK_KP_ENTER },
			{ "tab", SDLK_TAB },
			{"ctrl",SDLK_LCTRL},
			{"+",SDLK_PLUS},
			{ "-", SDLK_MINUS },
	};
}


KeyMapping::~KeyMapping()
{
}
std::unordered_map <SDL_Keycode, SDL_Keycode > KeyMapping::GetKeyMap(){
	std::ifstream settings;
	settings.open(keyMapLoc);
	std::string line;
	std::unordered_map <SDL_Keycode, SDL_Keycode>  keymap = std::unordered_map <SDL_Keycode, SDL_Keycode>();
	if (settings.is_open()) {

	
		while (getline(settings, line)) {
			std::istringstream is_line(line);
			std::string key;
			if (getline(is_line, key, '=')) {
				//TODO error handling on key, catch filthy people that will break the system
				std::string value;
				if (getline(is_line, value)) {
					auto it = KeyCodeMap.find(key);
					if (it != KeyCodeMap.end()){
						auto it2 = KeyCodeMap.find(value);
						if (it2 != KeyCodeMap.end()){
							keymap.emplace(it->second, it2->second);

						}
					}
			
				}
			}
		}
	
		
	}
	else {
		std::cout << "Unable to open Keysettings" << std::endl;
	}
	return keymap;

}