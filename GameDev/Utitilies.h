#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <iostream>

//Singleton class, for using helper methods
class Utilities {
	private:
		Utilities();
		static Utilities* instance;

		//generally the Utilities class doesn't need to know anything
		//it just needs to help with stuff
		//and make sure you can reuse certain code in different places

	public:
		~Utilities();
		static Utilities* GetInstance();


		//fyi, I'm still not quite sure if the class itself should be a singleton
		//or if the methods should just be static
		//both have their pros and cons


		//the important stuff
		void DrawTextHelper(SDL_Renderer* renderer, TTF_Font* font, std::string text, int x, int y, SDL_Color color);
		SDL_Color Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
		TTF_Font* SetFont(char* path, int ptsize);
};