#include "GameStateManager.h"
#include "IGameState.h"
#include "MenuState.h"
#include "PlayState.h"
#include <iostream>
#include <Windows.h>



GameStateManager::GameStateManager(){
	states = std::vector<IGameState*>();
	//TODO states onthouden
	PushGameState(new MenuState());
	//PushGameState(new PlayState());
}


void GameStateManager::ChangeGameState(IGameState* gameState)
{
	while (!states.empty())
	{
		states.back()->Cleanup();
		states.pop_back();
	}

	states.push_back(gameState);
	states.back()->Init(this);
}

void GameStateManager::PushGameState(IGameState* gameState)
{
	if (!states.empty())
	{
		states.back()->Pause();
	}

	states.push_back(gameState);
	states.back()->Init(this);
}

void GameStateManager::PopState()
{
	if (!states.empty())
	{
		states.back()->Cleanup();
		states.pop_back();
	}

	if (!states.empty())
	{
		states.back()->Resume();
	}
}


void GameStateManager::Cleanup()
{
	//While there are states on the stack, clean them up
	while (!states.empty())
	{
		//Peek at top state and clean that state
		states.back()->Cleanup();

		//Remove top state
		states.pop_back();
	}

	
}
IGameState* GameStateManager::GetCurrentState(){
	return states.back();

}
GameStateManager::~GameStateManager()
{
		while (!states.empty())
	{
		//Peek at top state and clean that state
		states.back()->Cleanup();

		//Remove top state
		states.pop_back();
	}

	
}
