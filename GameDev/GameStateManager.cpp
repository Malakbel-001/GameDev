#include "GameStateManager.h"
#include "IGameState.h"
#include "MenuState.h"
#include "PlayState.h"
#include "LoadState.h"
#include <iostream>


GameStateManager::GameStateManager(BehaviourFactory* _bf)
{
	states = std::vector<IGameState*>();
	bf = _bf;
	//TODO states onthouden

}
void GameStateManager::CreateGameState(GameStateType state)
{
	IGameState* gamestate;
	switch (state)
	{
	case GameStateType::PlayState:
		gamestate = new PlayState();

		break;
	case GameStateType::PauseState:
		//state = new PauseState();
		break;
	case GameStateType::MenuState:
		gamestate = new MenuState();
		break;
	case GameStateType::LoadState:
		gamestate = new LoadState();
		break;
	default:
		break;
	}


	PushGameState(gamestate);
}

void GameStateManager::ChangeGameState()
{
	if (!states.empty())
	{
		states.back()->Cleanup();
		states.pop_back();
	}

}

void GameStateManager::PushGameState(IGameState* gameState)
{


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
IGameState* GameStateManager::GetCurrentState()
{
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

void GameStateManager::SetBehaviour(BehaviourFactory* _bf){
	bf = _bf;
}
BehaviourFactory* GameStateManager::GetBehaviour()
{

	return bf;
}
