#pragma once
#include "Level.h"
class Level3 :
	public Level
{
protected:
	virtual void CreateMap();
	virtual void CreateNPCs();
	virtual void CreateParallaxBackground(BehaviourFactory* bf);

	int bossCount;
public:
	Level3(int _lvlWidth, int _lvlHeight);
	virtual ~Level3();

	void Cleanup();

	virtual Level* CreateLevel();
	virtual Player* SetPlayer(Player* _player);
	void HandleEvents(SDL_Event mainEvent);

	virtual ParallaxBackground* GetParallaxBackGround();
	int GetBossCount();
	void DecrementBossCount();
};

