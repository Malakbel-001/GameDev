#include "Game.h"



Game::Game(){

	running = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		//TODO
	}
	// Create the window where we will draw.
	window = SDL_CreateWindow("SDL_RenderClear",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		512, 512, 0);
	// We must call SDL_CreateRenderer in order for draw calls to affect this window.
	renderer = SDL_CreateRenderer(window, -1, 0);

	// Select the color for drawing. It is set to red here.
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	// Clear the entire screen to our selected color.
	SDL_RenderClear(renderer);

	// Up until now everything was drawn behind the scenes.
	// This will show the new, red contents of the window.
	SDL_RenderPresent(renderer);

	gameLoop();
}


Game::~Game()
{
	delete window;
	delete renderer;

}

void Game::inputManager() {
	while (SDL_PollEvent(&events)) {
		if (events.type == SDL_QUIT)
			running = false;
	}
}

void Game::gameLoop(){
	
int lastTime = GetTickCount() - 1;
	while (running){
		//Checks if windows is not closed
		inputManager();
		//Time to be used by behaviours
		int time = GetTickCount() - lastTime;
		//std::cout << time << "/n";
		//TODO UPDATE Behaviours with Time

		//
		
		std::cout << 1000l / time << " - ";
		lastTime = GetTickCount();
		
		// max 60 fps		
		SDL_Delay(16);

	}
	
	SDL_Quit();
	


}
