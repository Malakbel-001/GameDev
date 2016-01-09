#include "GameStateManager.h"
#include "PlayState.h"
#include "LoadState.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "VictoryState.h"
#include "MenuState.h"
#include "EditorState.h"
#include "EditorSubState.h"
#include <iostream>

GameStateManager::GameStateManager(BehaviourFactory* _bf)
{
	states = std::vector<IGameState*>();
	bf = _bf;
	//TODO states onthouden

}

//Give level, Create PlayState with Level
void GameStateManager::CreatePlayState(int lvl)
{
	IGameState* gamestate = GetNewState(GameStateType::PlayState, lvl, "");
	PushGameState(gamestate);
}

//Give level, Create EditorState with Level
void GameStateManager::CreateEditorState(int lvl)
{
	IGameState* gamestate = GetNewState(GameStateType::EditorState, lvl, "");
	PushGameState(gamestate);
}

void GameStateManager::CreateEditorState(std::string levelName)
{
	IGameState* gamestate = GetNewState(GameStateType::EditorState, 0, levelName);
	PushGameState(gamestate);
	//IGameState* gamestate = GetNewState(GameStateType::EditorState)
}

//Give GameState, Creates new GameState
void GameStateManager::CreateGameState(GameStateType state)
{
	IGameState* gamestate = GetNewState(state, 0, "");
	PushGameState(gamestate);
}

//Create / Load State
IGameState* GameStateManager::GetNewState(GameStateType state, int lvl, std::string name) 
{
	IGameState* gamestate;
	switch (state)
	{
	case GameStateType::PlayState:
		gamestate = new PlayState(lvl);
		break;
	case GameStateType::EditorState:
		if (name != "")
			gamestate = new EditorState(name);
		else if (lvl != 0)
			gamestate = new EditorState(lvl);
		else
			gamestate = new EditorState();
		break;
	case GameStateType::PauseState:
		gamestate = new PauseState();
		break;
	case GameStateType::MenuState:
		gamestate = new MenuState();
		break;
	case GameStateType::LoadState:
		gamestate = new LoadState(lvl);
		break;
	case GameStateType::GameOverState:
		gamestate = new GameOverState();
		break;
	case GameStateType::VictoryState:
		gamestate = new VictoryState();
		break;
	case GameStateType::EditorSubState:
		gamestate = new EditorSubState();
	default:
		break;
	}
	
	return gamestate;
}

//TODO, private / protected state? Would make more sense
void GameStateManager::PushGameState(IGameState* gameState)
{
	states.push_back(gameState);
	states.back()->Init(this);
}

//TODO, private / protected state? Would make more sense
void GameStateManager::PushGameStateOnly(IGameState* gameState) {
	IGameState* a = states.back();
		states.pop_back(); //pop loadState
		delete a;
	states.push_back(gameState);
	states.back()->Resume();
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

		states.back()->Resume(); //tell the state it is being resumed
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
