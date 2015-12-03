#include "GameStateManager.h"
#include "PlayState.h"
#include "LoadState.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "VictoryState.h"
#include "MenuState.h"
#include <iostream>

GameStateManager::GameStateManager(BehaviourFactory* _bf)
{
	states = std::vector<IGameState*>();
	bf = _bf;
	//TODO states onthouden

}

void GameStateManager::CreateGameState(GameStateType state)
{
	IGameState* gamestate = GetNewState(state);
	PushGameState(gamestate);
}

//Create / Load State
IGameState* GameStateManager::GetNewState(GameStateType state) 
{
	IGameState* gamestate;
	switch (state)
	{
	case GameStateType::PlayState:
		gamestate = new PlayState();
		break;
	case GameStateType::PauseState:
		gamestate = new PauseState();
		break;
	case GameStateType::MenuState:
		gamestate = new MenuState();
		break;
	case GameStateType::LoadState:
		gamestate = new LoadState();
		break;
	case GameStateType::GameOverState:
		gamestate = new GameOverState();
		break;
	case GameStateType::VictoryState:
		gamestate = new VictoryState();
		break;
	default:
		break;
	}
	
	return gamestate;
}


void GameStateManager::PushGameState(IGameState* gameState)
{
	states.push_back(gameState);
	states.back()->Init(this);
}

void GameStateManager::PushGameStateOnly(IGameState* gameState) {
	IGameState* a = states.back();
		states.pop_back(); //pop loadState
		delete a;
	states.push_back(gameState);
}
void GameStateManager::PopPrevState(){
	if (states.size() > 1){
		IGameState* a = states[states.size() - 2];

		states.erase(----states.end());
	//	delete a;
	}
}
void GameStateManager::PopState()
{
	if (!states.empty())
	{
		IGameState* a = states.back();
		//states.back()->Cleanup();
		
		states.pop_back();
	//	delete a;
	}

	
}


void GameStateManager::Cleanup()
{
	//While there are states on the stack, clean them up
	while (!states.empty())
	{
		//Peek at top state and clean that state
		

		//Remove top state
		states.pop_back();
	}
}
IGameState* GameStateManager::GetCurrentState()
{
	return states.back();
}

IGameState* GameStateManager::GetPreviousState()
{
	return states.at(states.size() -2);

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
