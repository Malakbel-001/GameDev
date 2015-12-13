#pragma once
#include "Level.h"
class LoadedLevel :
	public Level
{
public:
	LoadedLevel(int _lvlWidth, int _lvlHeight, b2Vec2 vec, PlayState* play);
	~LoadedLevel();
	virtual Player* SetPlayer(Player* _player); //pure virtual
	virtual Level* CreateLevel();			//pure virtual

	void Init(BehaviourFactory* bf);
};

