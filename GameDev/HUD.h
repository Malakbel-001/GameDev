#pragma once
#include "Player.h"

class HUD {
	private:
		SDL_Renderer* renderer;
		Player* player;
		
		SDL_Color Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
		void DrawHPBar(int x, int y, int w, int h, float Percent, SDL_Color FGColor, SDL_Color BGColor);
		void DrawAmmo();
		void DrawScore();
		//draw timer

	public:
		HUD(SDL_Renderer* renderer, Player* player);
		~HUD();
		void Draw();
};