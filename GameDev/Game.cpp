#include "Game.h"



Game::Game(){
	gameManager = GameStateManager();
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
void Game::setUpBox2D(){

}

void Game::gameLoop(){
	
	int lastTime = SDL_GetTicks() - 1;
//	gameManager.GetLevel()->GetWorld().Step(1.0 / 30.0, 1, 1);
	//b2World* currentWorld = gameManager.GetLevel()->GetWorld();
	while (running){

		//UPDATE WORLD
		//first parameter is fps , second end third parameter increase how precies hitcalculation are the higher the slower the program runs
		gameManager.GetLevel()->GetWorld()->Step(1.0 / 60.0, 5, 5);
		//Checks if windows is not closed
		//TODO for other input
		inputManager();
		//Time to be used by behaviours
	
		//TODO UPDATE Behaviours with Time
		int time = SDL_GetTicks() - lastTime;
		lastTime = SDL_GetTicks();
	
		// max 60 fps	
		if (1000.0 / 60 > time){
			SDL_Delay((1000.0 / 60) - time);
		}

	}	
	SDL_Quit();
}
