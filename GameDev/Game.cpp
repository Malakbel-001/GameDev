#pragma once
#include "Game.h"
#include "SoundFactory.h" //testing purposed, TODO remove
#include "SoundBank.h"



Game::Game(){
	gameManager = GameStateManager();
	running = true;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0){
		//TODO
	}
	// Create the window where we will draw.
	window = SDL_CreateWindow("SDL_RenderClear",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		512, 512, 0);

	// Open Audio & Start SDL_Mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048 < 0)) {
		std::cout << "Error: " << Mix_GetError() << std::endl;
	}

	// Set Amount of Channels to 2000, temporarily.
	// Later this will have to be changed to a dynamic amount using SoundBank and a cleanup loop every ?? seconds/updates
	// It's probably not a good idea to change the size 1000 times a second though.
	Mix_AllocateChannels(2000); //Temp

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

void Game::inputManager(int* i) { //temp parameter
	while (SDL_PollEvent(&events)) {
		if (events.type == SDL_QUIT)
			running = false;
		//AUDIO TESTING PURPOSES, TODO -> remove
		else if (events.type == SDL_KEYDOWN) {
			switch (events.key.keysym.sym) {
				case SDLK_1:
					SoundBank::GetInstance()->Play(SoundEffectType::CORRECT, 64);
					std::cout << Mix_Playing(-1) << std::endl; //get amount channels playing
					break;
				case SDLK_2:
					SoundBank::GetInstance()->Play(SoundEffectType::CORRECT, 128);
					std::cout << Mix_Playing(-1) << std::endl; //get amount channels playing
					break;
				case SDLK_3:
					break;
				case SDLK_4:
					std::cout << Mix_AllocateChannels(-1) << std::endl;
					break;
				case SDLK_5: //BGM1
					SoundBank::GetInstance()->PlayBGM(SoundBgmType::TESTBGM2, 64);
					break;
				case SDLK_6: //BGM2
					SoundBank::GetInstance()->PlayBGM(SoundBgmType::TESTBGM1, 32);
					break;
				case SDLK_p:
					SoundBank::GetInstance()->PauseOrResume();
					break;
				case SDLK_s:
					Mix_HaltMusic();
					break;
			}
		}
	}
}
void Game::setUpBox2D(){

}

void Game::gameLoop(){
	
	int lastTime = SDL_GetTicks() - 1;
//	gameManager.GetLevel()->GetWorld().Step(1.0 / 30.0, 1, 1);
	//b2World* currentWorld = gameManager.GetLevel()->GetWorld();

	SDL_Event ev;

	int durr = 0;
	int* i = &durr;

	while (running){

		//UPDATE WORLD
		//first parameter is fps , second end third parameter increase how precies hitcalculation are the higher the slower the program runs
		gameManager.GetLevel()->GetWorld()->Step(1.0 / 60.0, 5, 5);
		//Checks if windows is not closed
		//TODO for other input
		inputManager(i);
		//Time to be used by behaviours
	
		//TODO UPDATE Behaviours with Time
		int time = SDL_GetTicks() - lastTime;
		lastTime = SDL_GetTicks();
	
		// max 60 fps	
		if (1000.0 / 60 > time){
			SDL_Delay((1000.0 / 60) - time);
		}

	}	
	SoundBank::GetInstance()->FreeMemory();//do this before Mix_Quit or destroy soundBank before Mix_Quit

	Mix_Quit();
	SDL_Quit();
}
