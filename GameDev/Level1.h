#pragma once
#include <SDL.h>
#include "Level.h"

class Level1 :
	public Level
{
	private:
		// stuff

	protected:
		// stuff

	public:
		Level1(int _lvlWidth, int _lvlHeight , PlayState* play);
		virtual ~Level1();
		
		void Init(BehaviourFactory* bf);
		void Cleanup();

		virtual Level* CreateLevel();
		virtual Player* SetPlayer(Player* _player);
		void HandleEvents(SDL_Event mainEvent);


};

