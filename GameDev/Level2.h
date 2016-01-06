#pragma once
#include <SDL.h>
#include "Level.h"
class Level2 : public Level
{
	protected:
		virtual void CreateMap();
		virtual void CreateNPCs();
		virtual void CreateParallaxBackground(BehaviourFactory* bf);

	public:
		Level2(int _lvlWidth, int _lvlHeight, PlayState* play);
		Level2(int _lvlWidth, int _lvlHeight);
		virtual ~Level2();

		void Cleanup();

		virtual Level* CreateLevel();
		virtual Player* SetPlayer(Player* _player);
		void HandleEvents(SDL_Event mainEvent);
};

