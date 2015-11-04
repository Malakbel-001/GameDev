#pragma once
#include <SDL.h>
#include "Level.h"
#include "Tile.h"
#include "GameStateManager.h"

class testLevel :
	public Level
{
	private:
		// stuff

	protected:
		// stuff

	public:
		testLevel(int _lvlWidth, int _lvlHeight);
		virtual ~testLevel();

		void Init();
		void Cleanup();

		void HandleEvents(SDL_Event mainEvent);
	
		
};

