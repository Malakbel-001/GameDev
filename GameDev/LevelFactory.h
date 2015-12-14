#pragma once
#include <vector>
#include "Box2D\Box2D.h"
#include "Level1.h"
#include "Level2.h"
#include "GameStateManager.h"


class Level;

class LevelFactory
{
public:
	static Level* GetNextLevel(Level*, PlayState* play);
	static Level* GetFirstLevel(PlayState* play);
	static Level* GetSpecificLevel(PlayState* play,int lvl);
	static void DeletePointers();
private:
	LevelFactory();
	~LevelFactory();
	static void Init(PlayState* play);
	static std::vector<Level*> levels;
	
};

