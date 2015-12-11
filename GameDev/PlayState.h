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

class PlayState :
	public IGameState
{
	private:
	
		Player* player;
		Level* currentLevel;
		HUD* hud;
		bool gameOver;
		bool victory;

	public:

		void Init(GameStateManager *gsm);
		void Cleanup();

		void Pause();
		void Resume();

		void HandleMouseEvents(SDL_Event mainEvent);
		void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
		void Update(float);
		void Draw();
		void Move(float dt);
		void GameOver();
		void Victory();

		Player* GetPlayer();

		Level* GetCurrentLevel();
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

