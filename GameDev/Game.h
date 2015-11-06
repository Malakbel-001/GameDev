#pragma once
#include <SDL.h>
#include <SDL_image.h> 
#include <stdio.h> 
#include <string>
#include <iostream>
#include "IGameState.h"
#include "BehaviourFactory.h"
#include "SoundBank.h"
#include "InputManager.h"
#include "LTexture.h"
#include "GameStateManager.h"
#include "Level.h"

class Game
{
	public:
		Game();
		~Game();

		void GameLoop();
	
	private:
		bool running = true;
		SDLInitializer* sdlInitializer;
		GameStateManager* gsm;
		IGameState* gameState;
		InputManager* inputManager;
		void  SDLEvents();

		const int SCREEN_WIDTH = 1080;
		const int SCREEN_HEIGHT = 700;
	
		SDL_Event events;
};
