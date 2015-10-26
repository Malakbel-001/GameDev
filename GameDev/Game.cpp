#pragma once
#include "Game.h"
#include "SoundFactory.h" //testing purposed, TODO remove
#include "CSoundBank.h"
#include "SoundMemory.h"



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

	//audio test
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048 < 0)) {
		std::cout << "Error: " << Mix_GetError() << std::endl;
	}

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

void Game::inputManager(SoundMemory sm) { //temp parameter
	//AUDIO TEST! TEMPORARY PLACEMENT. Fyi, only accepts
	//Mix_Music general rule: 10 seconds or longer
	//Mix_Chunk general rule: shorter than 10 seconds
	Mix_Music *bgm = Mix_LoadMUS("../Assets/lastcave.mp3");
	Mix_Music *bgm2 = Mix_LoadMUS("../Assets/balcony.mp3");
	Mix_Music *bgmEmpty = nullptr;


	while (SDL_PollEvent(&events)) {
		if (events.type == SDL_QUIT)
			running = false;
		//AUDIO TESTING PURPOSES, TODO -> remove
		else if (events.type == SDL_KEYDOWN) {
			switch (events.key.keysym.sym) {
				case SDLK_1:
					sm.sound1();
					break;
				case SDLK_2:
					sm.sound2();
					break;
				case SDLK_p:
					//CSoundBank::SoundControl.PlayBGM("../Assets/lastcave.mp3");
					SoundFactory::SetNextBGM(bgm);
					break;
				case SDLK_t:
					//CSoundBank::SoundControl.PlayBGM("../Assets/balcony.mp3");
					break;
				case SDLK_e:
					//CSoundBank::SoundControl.PlayBGM("empty");
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

	//SDL Sound Tests
	SoundMemory sm = SoundMemory();


	while (running){

		//UPDATE WORLD
		//first parameter is fps , second end third parameter increase how precies hitcalculation are the higher the slower the program runs
		gameManager.GetLevel()->GetWorld()->Step(1.0 / 60.0, 5, 5);
		//Checks if windows is not closed
		//TODO for other input
		inputManager(sm);
		//Time to be used by behaviours
	
		//TODO UPDATE Behaviours with Time
		int time = SDL_GetTicks() - lastTime;
		lastTime = SDL_GetTicks();
	
		// max 60 fps	
		if (1000.0 / 60 > time){
			SDL_Delay((1000.0 / 60) - time);
		}

	}	
	CSoundBank::SoundControl.OnCleanup();

	Mix_Quit();
	SDL_Quit();
}
