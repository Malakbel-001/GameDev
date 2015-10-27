#include "LevelStateManager.h"
#include "ILevelState.h"

LevelStateManager LevelStateManager::m_Lsm;

LevelStateManager::LevelStateManager()
{
}


LevelStateManager::~LevelStateManager()
{

}

void LevelStateManager::init(GameStateManager* gsm)
{
	this->GSM = gsm;
}

void LevelStateManager::changeLevel(ILevelState* gameState)
{
	while (!states.empty())
	{
		states.back()->cleanup();
		states.pop_back();
	}

	states.push_back(gameState);
	states.back()->init(LevelStateManager::Instance());
}

void LevelStateManager::pushLevel(ILevelState* gameState)
{
	if (!states.empty())
	{
		states.back()->pause();
	}

	states.push_back(gameState);
	states.back()->init(LevelStateManager::Instance());
}

void LevelStateManager::popLevel()
{
	if (!states.empty())
	{
		states.back()->cleanup();
		states.pop_back();
	}

	if (!states.empty())
	{
		states.back()->resume();
	}
}

void LevelStateManager::handleEvents()
{
	// TODO: determen what needs to be here

}

void LevelStateManager::draw()
{
	
}

bool LevelStateManager::running()
{
	return m_running;
}

void LevelStateManager::quit()
{
	m_running = false;
}

void LevelStateManager::cleanup()
{
	//While there are states on the stack, clean them up
	while (!states.empty())
	{
		//Peek at top state and clean that state
		states.back()->cleanup();

		//Remove top state
		states.pop_back();
	}
}