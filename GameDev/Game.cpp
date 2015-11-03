#include "Game.h"
#include "SoundBank.h"
#include "header_loader.h"

using namespace std;
Game::Game()
{
	//gameManager = GameStateManager();
	//running = true;
	//if (SDL_Init(SDL_INIT_VIDEO) < 0)
	//{
	//	//TODO
	//}
	//// Create the window where we will draw.
	//window = SDL_CreateWindow("SDL_RenderClear",
	//	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	//	512, 512, 0);
	//// We must call SDL_CreateRenderer in order for draw calls to affect this window.
	//renderer = SDL_CreateRenderer(window, -1, 0);

	//// Select the color for drawing. It is set to red here.
	//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	//// Clear the entire screen to our selected color.
	//SDL_RenderClear(renderer);

	//gameLoop();

	gsm = new GameStateManager();
	gsm->Init("GameDev", ScreenWidth, ScreenHeight, fullScreen);
	//Non-threaded
	this->GameLoop(gsm);

	gsm->Cleanup();
}

Game::~Game()
{
	//delete window;
	//delete renderer;
}

void Game::InputManager(GameStateManager* gsm)
{
	while (SDL_PollEvent(&events))
	{
		if (events.type == SDL_QUIT)
			gsm->Quit();

		//User presses a key
		if (events.type == SDL_KEYDOWN)
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

				//sound test
				//case SDLK_1:
				//	SoundBank::GetInstance()->Play(SoundEffectType::CORRECT, 64);
				//	std::cout << Mix_Playing(-1) << std::endl; //get amount channels playing
				//	break;
				//case SDLK_2: //BGM1
				//	SoundBank::GetInstance()->PlayBGM(SoundBgmType::TESTBGM2, 64);
				//	break;
				//case SDLK_3:
				//	SoundBank::GetInstance()->PauseOrResume();
				//	break;
				//case SDLK_4:
				//	SoundBank::GetInstance()->StopMusic();
				//	break;
			} 
		}
	}
}

void Game::GameLoop(GameStateManager* gsm)
{	
	double TARGET_FPS = 60;
	double OPTIMAL_TIME = 1000 / TARGET_FPS;

	Uint32 previousLoopTime, currentLoopTime, afterLoopTime; // ticks

	previousLoopTime = SDL_GetTicks();

	Uint32 lastFpsUpdateTime = 0;
	int fps = 0;

	int lastTime = SDL_GetTicks() - 1;

	while (gsm->Running())
	{
		//TODO UPDATE Behaviours with Time

		// get current time
		currentLoopTime = SDL_GetTicks();

		// Calculate update time
		Uint32 updateTime = currentLoopTime - previousLoopTime;
		previousLoopTime = currentLoopTime;

		// calculate DeltaTime
		double dt = updateTime / OPTIMAL_TIME;

		// Add time difrence to the lastFpsUpdateTime
		lastFpsUpdateTime += updateTime;

		// incrament fps, frame past
		fps++;
		
		// max 60 fps	
		if (lastFpsUpdateTime >= 1000)
		{
			gsm->SetFps(fps);
			lastFpsUpdateTime = 0;
			fps = 0;
		}

		// TODO: cap min fps?
		//if (dt < 4) dt = 4;

		gsm->HandleEvents();
		gsm->Update(dt);
		gsm->Draw();

		gsm->SetUpdateLength(updateTime);

		afterLoopTime = SDL_GetTicks();

		/*if ((previousLoopTime - afterLoopTime) + OPTIMAL_TIME > 0)
		{
			SDL_Delay(previousLoopTime - afterLoopTime + OPTIMAL_TIME);
		}*/
		SDL_Delay(100);
	}
	SDL_Quit();
}
