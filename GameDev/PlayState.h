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

		Player* getPlayer();
		Camera* getCamera();

		void init(GameStateManager *gsm);
		void cleanup();

		void pause();
		void resume();
		void setGameOver(bool gameOver);

		void handleEvents(SDL_Event mainEvent);

		void update(double dt);
		
		Level* getCurrentLevel();
		void setCurrentLevel(Level* lvl);

		void loadGame();
		void setFileToLoad(std::string fileName);

		void draw();

		static PlayState* Instance() { return &m_PlayState; };

		virtual ~PlayState();
};

