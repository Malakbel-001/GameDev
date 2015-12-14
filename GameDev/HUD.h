#pragma once
#include "Player.h"
#include "SDL_ttf.h"
#include <iostream>
#include "Utitilies.h"
#include "Timer.h"

class HUD {
	public:
		HUD(SDL_Renderer* renderer, Player* player);
		~HUD();

	private:
		SDL_Renderer* renderer;
		Player* player;

		int* screenWidth;
		int* screenHeight;

		void SetSurfacesAndTextures();
		void SetRectangles();

		void DrawHealth();
		void DrawAmmo();
		void DrawScore();
		void DrawTimer();
		void CheckIfScreenSizeChanged();

		bool wasFullScreen; //was before

	public:
		void Draw();
		void Cleanup();
		void ResumeChecks();

	private:
		TTF_Font* hudFont;
		TTF_Font* timerFont;
		SDL_Color oldColor;
		Timer timer;
		
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

		SDL_Rect timerRect;
};