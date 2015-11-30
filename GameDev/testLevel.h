#pragma once
#include <SDL.h>
#include "Level.h"

class TestLevel :
	public Level
{
	public:
		TestLevel(int _lvlWidth, int _lvlHeight , PlayState* play);
		virtual ~TestLevel();
		
		void Init(BehaviourFactory* bf);
		void Cleanup();

		virtual Level* CreateLevel();
		void HandleEvents(SDL_Event mainEvent);		
};

