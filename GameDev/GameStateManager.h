#pragma once

#include "Level.h"
#include "LevelFactory.h"
class GameStateManager
{
public:
	GameStateManager();
	~GameStateManager();
	Level* GetLevel();
private:
	Level* currentLevel;

};

