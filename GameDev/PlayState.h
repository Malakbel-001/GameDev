#pragma once
#include "IGameState.h"
#include "header_loader.h"
#include "Player.h"
#include "Camera.h"
#include <iostream>

class PlayState :
	public IGameState
{
	private:
		static PlayState m_PlayState;

		GameStateManager* gsm;
		Camera* camera;
		Player* p;
		Level* currentLevel;

		std::string fileToLoad;

		int timesUpdate;
		bool gameOver;

	public:
		PlayState();

		Player* GetPlayer();
		Camera* GetCamera();

		void Init(GameStateManager *gsm);
		void Cleanup();

		void Pause();
		void Resume();
		void SetGameOver(bool gameOver);

		void HandleEvents(SDL_Event mainEvent);

		void Update(double dt);
		
		Level* GetCurrentLevel();
		void SetCurrentLevel(Level* lvl);

		void LoadGame();
		void SetFileToLoad(std::string fileName);

		void Draw();

		static PlayState* Instance() { return &m_PlayState; };

		virtual ~PlayState();
};

