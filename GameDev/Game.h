#pragma once
#include "SDL.h"
#include <iostream>
class Game
{
public:
	
	Game();
	~Game();

	void gameLoop();
	
private:
	void inputManager();

	SDL_Window* window;
	SDL_Renderer* renderer;	
	SDL_Event events;

	bool running;
};

