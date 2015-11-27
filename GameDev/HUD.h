#pragma once
#include "Player.h"

class HUD {
	private:
		SDL_Renderer* renderer;
		Player* player;

		SDL_Color Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
		int Clamp(int var, int min, int max);
		void DrawHPBar(int x, int y, int width, int height, float diminisher, SDL_Color hpColor);
		void DrawAmmo();
		void DrawScore();
		//draw timer

	public:
		HUD(SDL_Renderer* renderer, Player* player);
		~HUD();
		void Draw();
};