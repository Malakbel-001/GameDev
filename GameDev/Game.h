#pragma once
#include "GameStateManager.h"
#include <iostream>
#include "GameStateManager.h"
#include "Level.h"

class Game
{
public:
	GameStateManager gameManager;
	Game();
	~Game();

	void gameLoop(GameStateManager* gsm);
	

private:
	GameStateManager* gsm;
	void inputManager(GameStateManager* gsm);

	void setUpBox2D();

	
	SDL_Window* window;
	SDL_Renderer* renderer;	
	SDL_Event events;

	bool running;	
};

