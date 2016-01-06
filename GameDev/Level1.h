#pragma once
#include <SDL.h>
#include "Level.h"

class Level1 :
	public Level
{
	protected:
		virtual void CreateMap();
		virtual void CreateNPCs();
		virtual void CreateParallaxBackground(BehaviourFactory* bf);

	public:
		Level1(int _lvlWidth, int _lvlHeight);
		virtual ~Level1();
		
		void Cleanup();

		virtual Level* CreateLevel();
		virtual Player* SetPlayer(Player* _player);
		void HandleEvents(SDL_Event mainEvent);
};