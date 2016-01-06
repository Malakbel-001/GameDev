#pragma once
#include "Level.h"
class LoadedLevel :
	public Level
{
public:
	LoadedLevel(int _lvlWidth, int _lvlHeight, b2Vec2 vec, PlayState* play);
	LoadedLevel(int _lvlWidth, int _lvlHeight, b2Vec2 vec);
	~LoadedLevel();
	virtual Player* SetPlayer(Player* _player); //pure virtual
	virtual Level* CreateLevel();			//pure virtual

	
protected:
	virtual void CreateMap();
	virtual void CreateNPCs();
	virtual void CreateParallaxBackground(BehaviourFactory* bf);
};

