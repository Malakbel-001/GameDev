#pragma once

#include "Level.h"
#include "LevelFactory.h"
class GameStateManager
{
public:
	GameStateManager();
	virtual ~GameStateManager();
	Level* GetLevel();
private:
	Level* currentLevel;

};

