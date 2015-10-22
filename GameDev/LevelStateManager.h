#pragma once
#include <vector>
#include "Level.h"
#include "SDLInitializer.h"
#include "GameStateManager.h"

class ILevelState;

class LevelStateManager
{
	private:
		std::vector<ILevelState*> states;
		ILevelState* currentLevel;
		bool m_running;
		GameStateManager* GSM;

		static LevelStateManager m_Lsm;

	public:
		LevelStateManager();
		virtual ~LevelStateManager();

		void init(GameStateManager* gsm);
		void cleanup();

		void setFps(int fps);
		int getFps();

		void changeLevel(ILevelState* lvlState);
		void pushLevel(ILevelState* lvlState);
		void popLevel();

		void update(double delta);
		void handleEvents();
		void flushEvents();
		void draw();

		// for quiting mission maybe?
		bool running();
		void quit();

		static LevelStateManager* Instance()
		{
			return &m_Lsm;
		};
	};
