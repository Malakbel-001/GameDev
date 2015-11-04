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
		GameStateManager(BehaviourFactory* _bf);
		void Cleanup();
		void ChangeGameState(IGameState* gameState);
		void PushGameState(IGameState* gameState);
		void PopState();
		void CreateGameState(GameStateType state);
		IGameState* GetCurrentState();
		virtual ~GameStateManager();
};
