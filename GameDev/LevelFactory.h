#pragma once
#include <vector>
#include "Box2D\Box2D.h"
#include "TestLevel.h"
#include "GameStateManager.h"


class Level;

class LevelFactory
{
public:
	static Level* GetNextLevel(Level*, PlayState* play);
	static Level* GetFirstLevel(PlayState* play);
private:
	LevelFactory();
	~LevelFactory();
	static void Init(PlayState* play);
	static std::vector<Level*> levels;
	
};

