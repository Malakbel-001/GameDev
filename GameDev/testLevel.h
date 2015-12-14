#pragma once
#include <SDL.h>
#include "Level.h"

class TestLevel :
	public Level
{
	protected:
		virtual void CreateMap();
		virtual void CreateNPCs();
		virtual void CreateParallaxBackground(BehaviourFactory* bf);

	public:
		TestLevel(int _lvlWidth, int _lvlHeight , PlayState* play);
		virtual ~TestLevel();
		
		void Init(BehaviourFactory* bf);
		void Cleanup();

		virtual Level* CreateLevel();
		virtual Player* SetPlayer(Player* _player);
		void HandleEvents(SDL_Event mainEvent);
};

