#pragma once
#include "Player.h"
#include "SDL_ttf.h"
#include <iostream>
#include "Utitilies.h"
#include "Timer.h"

class HUD {
	public:
		HUD();
		~HUD();

	private:
		SDL_Renderer* renderer;
		Player* player;

		int* screenWidth;
		int* screenHeight;

		void SetSurfacesAndTextures();

		const int y = 20;
		void SetUpperLeftRectangles(int x, int y);
		void SetUpperMiddleRectangles(int y);
		void SetUpperRightRectangles(int y);

		void DrawHealth();
		void DrawAmmo();
		void DrawScore();
		void DrawTimer(float dt, float manipulatorSpeed);
		void CheckIfScreenSizeChanged();

		bool wasFullScreen; //was before

	public:
		void Initialize(SDL_Renderer* _renderer, Player* _player);
		void Draw(float dt, float manipulatorSpeed);
		void Cleanup();
		void ResumeChecks();
		void SetTimer(Timer* timer);
		Timer* GetTimer();
		void SetPlayer(Player* newPlayer);

	private:
		TTF_Font* hudFont;
		TTF_Font* timerFont;
		SDL_Color oldColor;
		Timer* timer;
		
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