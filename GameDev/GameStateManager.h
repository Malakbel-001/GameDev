#pragma once

#include <SDL.h>
#include <vector>
#include "SDLInitializer.h"
#include "Level.h"
#include "LevelFactory.h"

class IGameState;

class GameStateManager
{
	private:		
		std::vector<IGameState*> states;


	public:	
		GameStateManager();		
		void Cleanup();
		void ChangeGameState(IGameState* gameState);
		void PushGameState(IGameState* gameState);
		void PopState();
		IGameState* GetCurrentState();
		virtual ~GameStateManager();
};
