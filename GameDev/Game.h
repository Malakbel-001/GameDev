#pragma once
#include "GameStateManager.h"
#include <iostream>

class Game
{
private:
	GameStateManager* gsm;
	void inputManager(GameStateManager* gsm);

	SDL_Window* window;
	SDL_Renderer* renderer;	
	SDL_Event events;

	bool running;

public:

	Game();
	~Game();

	void gameLoop(GameStateManager* gsm);
};

