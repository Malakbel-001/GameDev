#include "Game.h"
#include <iostream>

using namespace std;

Game::Game()
{
	running = true;	
	
	gameLoop();
}


Game::~Game()
{
	delete window;
	delete renderer;

}

void Game::inputManager() {
	while (SDL_PollEvent(&events)) 
	{
		//User requests quit
		if (events.type == SDL_QUIT)
		{ 
			running = false; 
		}
		//User presses a key
		else if (events.type == SDL_KEYDOWN)
		{ 
			//Select surfaces based on key press 
			switch (events.key.keysym.sym)
			{ 
				case SDLK_w:
					cout << "Jumping" << endl;
					break;
				case SDLK_s:
					cout << "Crouching" << endl;
					break;
				case SDLK_a:
					cout << "Moving Left" << endl;
					break;
				case SDLK_d:
					cout << "Moving Right" << endl;
					break;
				case SDLK_UP: 
					cout << "Aiming up" << endl;
					break; 
				case SDLK_DOWN: 
					cout << "Aiming down" << endl;
					break; 
				case SDLK_LEFT: 
					cout << "previous weapon" << endl;
					break; 
				case SDLK_RIGHT: 
					cout << "next weapon" << endl;
					break; 
			} 
		}
	}
}

void Game::gameLoop(){
	
	int lastTime = SDL_GetTicks() - 1;
	int frame = 0;

	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			while (running){
				//Checks if windows is not closed
				inputManager();
				//Time to be used by behaviours
				int time = SDL_GetTicks() - lastTime;
				//TODO UPDATE Behaviours with Time

				lastTime = SDL_GetTicks();

				// max 60 fps		
				//SDL_Delay(16);
				SDL_Delay(100);
				
				//Clear screen
				drawableContainer.ClearScreen();

				//Render current frame 
				SDL_Rect* currentClip = &idleSprites[ frame / 3 ]; 
				spriteSheetTexture.render( renderer, ( SCREEN_WIDTH - currentClip->w ) / 2, ( SCREEN_HEIGHT - currentClip->h ) / 2, currentClip );

				//Update screen
				SDL_RenderPresent(renderer);

				//Go to next frame 
				++frame; 
				
				//Cycle animation 
				if (frame / IDLE_ANIMATION_FRAMES >= IDLE_ANIMATION_FRAMES)
				{ 
					frame = 0; 
				}
			}
		}
	}
	SDL_Quit();
}

bool Game::init()
{
	//Initialization flag 
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		//TODO
	}
	// Create the window where we will draw.
	window = SDL_CreateWindow("SDL_RenderClear",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError()); 
		success = false;
	}
	else
	{
		// We must call SDL_CreateRenderer in order for draw calls to affect this window.
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		if (renderer == NULL)
		{
			printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError()); 
			success = false;
		}
		else
		{
			// Select the color for drawing. It is set to red here.
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

			// Create drawcontainer and clear screen
			drawableContainer = new DrawableContainer(renderer);
			drawableContainer.ClearScreen();
			
			// Up until now everything was drawn behind the scenes.
			// This will show the new, red contents of the window.
			SDL_RenderPresent(renderer);
			
			int imgFlags = IMG_INIT_PNG;

			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}
		}
	}
	return success;
}
