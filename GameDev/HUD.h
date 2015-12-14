#pragma once
#include "Player.h"
#include "SDL_ttf.h"
#include <iostream>

class HUD {
	public:
		HUD(SDL_Renderer* renderer, Player* player);
		~HUD();

	private:
		SDL_Renderer* renderer;
		Player* player;

		void SetRectangles(int x, int y);
		void SetHUDFont(char* path, int ptsize);

		SDL_Color Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

		void DrawHealth();
		void DrawAmmo();
		void DrawScore();
		void DrawTextHelper(std::string, int x, int y);
		//draw timer

	public:
		void Draw();
		void Cleanup();

	private:
		TTF_Font* hudFont;
		SDL_Color oldColor;
		
		SDL_Rect drawHPRect;
		SDL_Rect fillHPRect;
		SDL_Rect amountHPRect;

		SDL_Rect drawStatsRect;

		SDL_Surface* ammoSurface;
		SDL_Texture* ammoTexture;
		SDL_Rect ammoRect;

		SDL_Surface* scoreSurface;
		SDL_Texture* scoreTexture;
		SDL_Rect scoreRect;

		SDL_Surface* hpSurface;
		SDL_Texture* hpTexture;
		SDL_Rect hpRect;
};