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

	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	

	SDL_Window* window;
	SDL_Renderer* renderer;	
	SDL_Event events;

	SDL_Surface* spriteSheet = NULL;
	LTexture spriteSheetTexture;
		
	const int IDLE_ANIMATION_FRAMES = 3;
	const int WALK_ANIMATION_FRAMES = 9;
	SDL_Rect idleSprites[3];
	SDL_Rect walkSprites[9];

	bool running;
};

