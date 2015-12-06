#pragma once
#include <SDL.h>
#include "Level.h"
class Level2 : public Level
{
	private:
		ParallaxBackground* parallaxBackground;

	public:
		Level2(int _lvlWidth, int _lvlHeight, PlayState* play);
		virtual ~Level2();

		void Init(BehaviourFactory* bf);
		void Cleanup();

		virtual Level* CreateLevel();
		virtual Player* SetPlayer(Player* _player);
		void HandleEvents(SDL_Event mainEvent);

		virtual void SetParallaxBackground(SDL_Renderer*);
		virtual void SetBackgroundLayers();
		virtual ParallaxBackground* GetParallaxBackGround();
};

