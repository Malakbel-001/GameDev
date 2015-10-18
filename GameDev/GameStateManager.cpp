#include "GameStateManager.h"


GameStateManager::GameStateManager()
{
	currentLevel = LevelFactory::GetFirstLevel();
}
Level* GameStateManager::GetLevel(){
	return currentLevel;
}

GameStateManager::~GameStateManager()
{
}
