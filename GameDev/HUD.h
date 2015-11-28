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

		void SetHPBarRectangle(int x, int y, int width, int height);
		void SetHUDFont(char* path, int ptsize);

		SDL_Color Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
		int Clamp(int var, int min, int max);
		void DrawHPBar(float diminisher, SDL_Color hpColor);
		void DrawAmmo();
		void DrawScore();
		//draw timer

	public:
		void Draw();
		void Cleanup();

	private:
		TTF_Font* hudFont;
		SDL_Color oldColor;
		SDL_Rect drawRect;
		SDL_Rect fillRect;

};