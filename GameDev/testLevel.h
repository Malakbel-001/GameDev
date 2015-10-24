#pragma once
#include <SDL.h>
#include "Level.h"
#include "Tile.h"

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

		void init();
		void cleanup();

		void handleEvents(SDL_Event mainEvent);
		void update(double dt);
		void draw();
};

