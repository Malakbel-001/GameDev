#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <iostream>

//Namespace with Utility methods, you can just grab the namespace + methods and use them wherever to help you out
//This helps for reusing code and preventing to write code again
namespace Utilities {
	void DrawTextHelper(SDL_Renderer* renderer, TTF_Font* font, std::string text, int x, int y, SDL_Color color);
	SDL_Color GetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	TTF_Font* SetFont(char* path, int ptsize);
};