#include "Game.h"
#include "header_loader.h"

using namespace std;
Game::Game()
{
	sdlInitializer = new SDLInitializer();
	sdlInitializer->Init("Game", SCREEN_WIDTH, SCREEN_HEIGHT, false);
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
	
	//Non-threaded
	this->GameLoop();

	gsm->Cleanup();
}

Game::~Game()
{
	delete gsm;
	delete sdlInitializer;
	//delete window;
	//delete renderer;
}

void Game::InputManager()
{
	while (SDL_PollEvent(&events))
	{
		if (events.type == SDL_QUIT)
		{
			running = false;
		}
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
			} 
		}
	}
}

void Game::GameLoop()
{	
	float TARGET_FPS = 0.016666666 * 1000;


	Uint32 preLoopTime, afterLoopTime; // ticks

	preLoopTime = SDL_GetTicks() -1;



	while (running)
	{
	
		float dt = SDL_GetTicks() - preLoopTime;;
		preLoopTime = SDL_GetTicks();


		InputManager();
		gsm->GetCurrentState()->Update(dt);
		gsm->GetCurrentState()->Draw(sdlInitializer->GetRenderer());
			
	
		afterLoopTime = SDL_GetTicks();
		if (!((afterLoopTime - preLoopTime) > TARGET_FPS))
		{
			
			SDL_Delay(TARGET_FPS - (afterLoopTime - preLoopTime));
		}

	}
	
	SDL_Quit();
}
