#pragma once
#include "Level.h"
class Level3 :
	public Level
{
protected:

	virtual void LoadParallaxBackgroundSettings();

public:
	Level3(int _lvlWidth, int _lvlHeight, PlayState* play);
	virtual ~Level3();

	void Init(BehaviourFactory* bf);
	void Cleanup();

	virtual Level* CreateLevel();
	virtual Player* SetPlayer(Player* _player);
	void HandleEvents(SDL_Event mainEvent);

	virtual ParallaxBackground* GetParallaxBackGround();
};

