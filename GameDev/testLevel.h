#pragma once
#include <SDL.h>
#include "Level.h"

class TestLevel :
	public Level
{
	private:
		ParallaxBackground* parallaxBackground;

	protected:
		virtual void LoadParallaxBackgroundSettings();

	public:
		TestLevel(int _lvlWidth, int _lvlHeight , PlayState* play);
		virtual ~TestLevel();
		
		void Init(BehaviourFactory* bf);
		void Cleanup();

		virtual Level* CreateLevel();
		virtual Player* SetPlayer(Player* _player);
		void HandleEvents(SDL_Event mainEvent);

		virtual ParallaxBackground* GetParallaxBackGround();
};

