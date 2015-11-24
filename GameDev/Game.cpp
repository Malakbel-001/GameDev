#include "Game.h"
#include "header_loader.h"

using namespace std;
Game::Game()
{
	inputManager = new InputManager();
	sdlInitializer = new SDLInitializer();
	sdlInitializer->Init("Jark Hunter", SCREEN_WIDTH, SCREEN_HEIGHT, false);
	bf = new BehaviourFactory(sdlInitializer->GetRenderer(), SCREEN_WIDTH, SCREEN_HEIGHT);


	gsm = new GameStateManager(bf);
	gsm->CreateGameState(GameStateType::MenuState);

	//Non-threaded
	this->GameLoop();

	gsm->Cleanup();
}

Game::~Game()
{
	delete gsm;
	delete sdlInitializer;
}

void Game::SDLEvents()
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
			inputManager->SetKeyInput(events.key.keysym.sym);
		}

		if (events.type == SDL_KEYUP)
		{
			inputManager->ResetKeyInput(events.key.keysym.sym);
		}

		if (events.type == SDL_MOUSEBUTTONDOWN)
		{
			inputManager->SetMouseInput(events);
		}
		if (events.type == SDL_MOUSEMOTION)
		{
			inputManager->SetMouseMotion(events);
		}
	}
}

void Game::GameLoop()
{	
	float TARGET_FPS = static_cast<float>(0.016666666 * 1000);
	Uint32 preLoopTime, afterLoopTime; // ticks

	preLoopTime = SDL_GetTicks() -1;

	while (running)
	{
		float dt = SDL_GetTicks() - preLoopTime;;
		preLoopTime = SDL_GetTicks();

		SDLEvents();
		gsm->GetCurrentState()->HandleKeyEvents(inputManager->GetKeyInput());		
		gsm->GetCurrentState()->HandleMouseEvents(inputManager->GetMouseInput());
		inputManager->ResetMouseInput();
		gsm->GetCurrentState()->Update(dt);
		SDL_RenderClear(sdlInitializer->GetRenderer());
		gsm->GetCurrentState()->Draw();
		SDL_RenderPresent(sdlInitializer->GetRenderer());
	
		afterLoopTime = SDL_GetTicks();
		if (!((afterLoopTime - preLoopTime) > TARGET_FPS))
		{
			SDL_Delay(TARGET_FPS - (afterLoopTime - preLoopTime));
		}
	}
	
	SDL_Quit();
}
