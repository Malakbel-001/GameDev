#pragma once
#include <SDL.h>
#include "Level.h"
#include "Tile.h"
#include "GameStateManager.h"

class TestLevel :
	public Level
{
	private:
		// stuff

	protected:
		// stuff

	public:
		TestLevel(int _lvlWidth, int _lvlHeight);
		virtual ~TestLevel();

		void Init(BehaviourFactory* bf);
		void Cleanup();

		void HandleEvents(SDL_Event mainEvent);
	
		
};

