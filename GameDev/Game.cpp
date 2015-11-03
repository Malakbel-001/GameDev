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
	//AUDIO TEST! TEMPORARY PLACEMENT. Fyi, only accepts
	//Mix_Music general rule: 10 seconds or longer
	//Mix_Chunk general rule: shorter than 10 seconds
	/*Mix_Music* bgm = Mix_LoadMUS("../Assets/lastcave.mp3");
	Mix_Music* bgm2 = Mix_LoadMUS("../Assets/balcony.mp3");
	Mix_Music* bgmEmpty = nullptr;*/
	//Mix_LoadWAV("../Assets/lastcave.mp3");
	/*Mix_Chunk* chunkie = Mix_LoadWAV("../Assets/soundcorrect.wav");
	int channel;*/


	while (SDL_PollEvent(&events)) {
		if (events.type == SDL_QUIT)
			running = false;
		//AUDIO TESTING PURPOSES, TODO -> remove
		else if (events.type == SDL_KEYDOWN) {
			switch (events.key.keysym.sym) {
				case SDLK_1:
					SoundBank::getInstance()->Play(SoundEffectType::CORRECT);
					std::cout << Mix_Playing(-1) << std::endl;
					//soundBank.Play(SoundEffectType::CORRECT);

					/*Mix_VolumeChunk(chunkie, 64);
					Mix_PlayChannel(1, chunkie, 0);*/
					//i++;
					break;
				case SDLK_2:
					SoundBank::getInstance()->FreeMemory();
					std::cout << Mix_Playing(-1) << std::endl;
					/*Mix_VolumeChunk(chunkie, 90);
					Mix_PlayChannel(2, chunkie, 0);*/
					break;
				case SDLK_3:
					
					/*Mix_VolumeChunk(chunkie, 30);
					Mix_PlayChannel(3, chunkie, 0);*/
					break;
				case SDLK_4:
					std::cout << Mix_AllocateChannels(-1) << std::endl; //might throw errors
					//Mix_FreeChunk(chunkie);
					//Mix_PlayChannel(4, chunkie, 0);
					break;
				case SDLK_5:
					SoundBank::getInstance()->PlayBGM(SoundBgmType::TESTBGM2);
					//std::cout << Mix_PlayChannel(-1, chunkie, 0) << std::endl; //might throw errors
					//std::cout << "playing: "+Mix_Playing(channel) << std::endl; //might throw errors
					//Mix_PlayChannel(5, chunkie, 0);
					break;
				case SDLK_6:
					SoundBank::getInstance()->PlayBGM(SoundBgmType::TESTBGM1);
					//Mix_PlayChannel(6, chunkie, 0);
					break;
				case SDLK_p:
					//CSoundBank::SoundControl.PlayBGM("../Assets/lastcave.mp3");
					//SoundFactory::SetNextBGM(bgm);
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
	

	/*delete(bgm);
	delete(bgm2);
	delete(bgmEmpty);
	delete(chunkie);*/
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
	SoundBank* soundBank = SoundBank::getInstance();
	soundBank->FreeMemory(); //do this before Mix_Quit or destroy soundBank before Mix_Quit

	Mix_Quit();
	SDL_Quit();
}
