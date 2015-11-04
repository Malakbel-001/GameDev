#pragma once
#include "GameStateManager.h"
#include "Level.h"
#include "SDL.h"
#include "LTexture.h"
#include <SDL_image.h> 
#include <stdio.h> 
#include <string>
#include <iostream>
#include "IGameState.h"
#include "BehaviourFactory.h"

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
	void InputManager();

	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	

	SDL_Event events;

};

