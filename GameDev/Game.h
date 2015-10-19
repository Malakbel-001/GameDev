#pragma once
#include "SDL.h"
#include "LTexture.h"
#include <SDL_image.h> 
#include <stdio.h> 
#include <string>
#include <iostream>

class Game
{
public:
	
	Game();
	~Game();

	void gameLoop();
	bool loadSprites();
	bool loadMedia();
	bool init();
	SDL_Surface* loadSurface(std::string path);

private:
	void inputManager();

	SDL_Window* window;
	SDL_Renderer* renderer;	
	SDL_Event events;

	SDL_Surface* screenSurface = NULL;
	SDL_Surface* spriteSheet = NULL;
	LTexture spriteSheetTexture;

	int IDLE_ANIMATION_FRAMES = 3;
	SDL_Rect idleSprites[3];

	bool running;
};

