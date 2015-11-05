#pragma once
#include "IGameState.h"
#include "header_loader.h"
#include "Player.h"
#include "Camera.h"
#include "SoundBank.h"
#include "BehaviourFactory.h"
#include <iostream>

class PlayState :
	public IGameState
{
	private:
	

		GameStateManager* gsm;		
		Player* player;
		Level* currentLevel;	
		bool gameOver;

	public:

		void Init(GameStateManager *gsm);
		void Cleanup();

		void Pause();
		void Resume();

		void HandleMouseEvents(SDL_Event mainEvent);
		void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
		void Update(float dt);
		void Draw();


		Player* GetPlayer();


		

		Level* GetCurrentLevel();
		void SetCurrentLevel(Level* lvl);
		void LoadGame();

		void SetFileToLoad(std::string fileName);		
		

		virtual ~PlayState();
};

