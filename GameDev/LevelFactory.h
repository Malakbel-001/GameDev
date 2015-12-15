#pragma once
#include <vector>
#include "Box2D\Box2D.h"
#include "TestLevel.h"
#include "Level2.h"
#include "Level3.h"
#include "GameStateManager.h"


class Level;

class LevelFactory
{
public:
	static Level* GetNextLevel(Level*, PlayState* play);
	static Level* GetFirstLevel(PlayState* play);
	static void DeletePointers();
private:
	LevelFactory();
	~LevelFactory();
	static void Init(PlayState* play);
	static std::vector<Level*> levels;
	
};

