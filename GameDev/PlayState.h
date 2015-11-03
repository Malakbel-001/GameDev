#pragma once
#include "IGameState.h"
#include "header_loader.h"
#include "Player.h"
#include "Camera.h"
#include "BehaviourFactory.h"
#include <iostream>

class PlayState :
	public IGameState
{
	private:
		static PlayState m_PlayState;

		GameStateManager* gsm;
		Camera* camera;
		Entity* p;
		Level* currentLevel;
		BehaviourFactory* factory;
	

		std::string fileToLoad;

		int timesUpdate;
		bool gameOver;

	public:
		PlayState();
		DrawableContainer* drawableContainer;
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

