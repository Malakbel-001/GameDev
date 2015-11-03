#pragma once
#include "GameStateManager.h"
#include "Level.h"
#include "SDL.h"
#include "LTexture.h"
#include <SDL_image.h> 
#include <stdio.h> 
#include <string>
#include <iostream>

class Game
{
public:
	GameStateManager gameManager;
	Game();
	~Game();

	void GameLoop(GameStateManager* gsm);

private:
	GameStateManager* gsm;
	void InputManager();

	void SetUpBox2D();

	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	

	SDL_Window* window;
	SDL_Renderer* renderer;	
	SDL_Event events;

	bool running;	
};

