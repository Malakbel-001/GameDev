#pragma once
#include "SDL.h"
#include "SDL_mixer.h"
#include <iostream>
#include "GameStateManager.h"
#include "Level.h"

class Game
{
public:
	GameStateManager gameManager;
	Game();
	~Game();

	void gameLoop();
	
private:
	void inputManager(int* i);

	void setUpBox2D();

	
	SDL_Window* window;
	SDL_Renderer* renderer;	
	SDL_Event events;

	bool running;
};

