#pragma once
#include "Utitilies.h"

namespace Utilities {
	TTF_Font* Utilities::SetFont(char* path, int ptsize) {
		if (TTF_Init() == -1) //initialize TTF
			std::cout << " Failed to initialize TTF : " << TTF_GetError() << std::endl;

		TTF_Font* font = TTF_OpenFont(path, ptsize);

		if (font == nullptr)
			std::cout << " Failed to load font : " << TTF_GetError() << std::endl;

		return font;
	}

	//Draw Text on the specificied location
	void Utilities::DrawTextHelper(SDL_Renderer* renderer, TTF_Font* font, std::string text, int x, int y, SDL_Color color) {
		SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_Rect counterRect = { x, y, surface->w, surface->h };

		SDL_RenderCopy(renderer, texture, NULL, &counterRect);

		//cleanup counter stuff after using them
		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);
	}

	//Draw Text on the specified location, minusX and minus the text-surface-width
	void Utilities::DrawTextHelper(SDL_Renderer* renderer, TTF_Font* font, std::string text, int minusX, int y, SDL_Color color, int screenWidth) {
		SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_Rect counterRect = { screenWidth - (minusX + surface->w), y, surface->w, surface->h };

		SDL_RenderCopy(renderer, texture, NULL, &counterRect);

		//cleanup counter stuff after using them
		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);
	}

	//color - Returns an SDL_Color with the appropriate values
	SDL_Color Utilities::GetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
		SDL_Color col = { r, g, b, a };
		return col;
	}
}