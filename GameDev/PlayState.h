#pragma once
#include "IGameState.h"
#include "header_loader.h"
#include "Player.h"
#include "Camera.h"
#include "SoundBank.h"
#include "BehaviourFactory.h"
#include "Weapon.h"
#include <iostream>
#include "HUD.h"
#include "LevelConfig.h"

class PlayState :
	public IGameState
{
	private:
	
		LevelConfig levelConfig;

		Player* player;
		Level* currentLevel;
		HUD* hud;
		bool gameOver;
		bool victory;
		int levelToLoad;
	public:
		PlayState(int lvl);
		void Init(GameStateManager *gsm);
		void Cleanup();

		void Pause();
		void Resume();

		void HandleMouseEvents(SDL_Event mainEvent);
		void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
		void Update(float);
		void Draw(float);
		void GameOver();
		void Victory();

		Player* GetPlayer();

		Level* GetCurrentLevel();
		void InitStartLevel(int lvl);
		void SetCurrentLevel(Level* lvl);
		void LoadGame();

		void SetFileToLoad(std::string fileName);		
		

		virtual ~PlayState();

		//temp
		LTexture background;
		//background
		SDL_Rect backgroundRect;
		//background
		SDL_Texture* backgroundTexture;
};

