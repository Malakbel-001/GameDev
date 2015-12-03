#pragma once
#include <SDL.h>
#include <vector>
#include "SDLInitializer.h"
#include "Level.h"
#include "LevelFactory.h"
#include "GameStateType.h"

class IGameState;

class GameStateManager
{
	private:		
		std::vector<IGameState*> states;
		BehaviourFactory* bf;

	public:	
		BehaviourFactory* GetBehaviour();
		GameStateManager(BehaviourFactory* _bf);
		void SetBehaviour(BehaviourFactory* _bf);
		void Cleanup();
		void ChangeGameState();
		void PushGameState(IGameState* gameState);
		void PushGameStateOnly(IGameState* gameState);
		void PopState();
		void CreateGameState(GameStateType state);
		void PopPrevState();
		IGameState* GetNewState(GameStateType state);
		IGameState* GetCurrentState();
		IGameState* GetPreviousState();
		virtual ~GameStateManager();
};
