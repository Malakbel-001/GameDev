#include "GameStateManager.h"
#include "IGameState.h"
#include "MenuState.h"
#include "PlayState.h"
#include <iostream>
#include <Windows.h>

GameStateManager GameStateManager::m_Gsm;
GameStateManager::GameStateManager() { }

void GameStateManager::Init(const char* title, int width, int height, bool fullscreen)
{
	sdlInitializer = new SDLInitializer();
	sdlInitializer->Init(title, width, height, fullscreen);

	m_running = true;
	showFps = false;

	GameStateManager::Instance()->SetFps(0);
	this->updateLength = 0;

	GameStateManager::Instance()->ChangeGameState(PlayState::Instance());
}

void GameStateManager::SetUpdateLength(float updateLength)
{
	this->updateLength = updateLength;
}

void GameStateManager::SetFps(int fps)
{
	GameStateManager::Instance()->fps = fps;
}

int GameStateManager::GetFps()
{
	return GameStateManager::Instance()->fps;
}

void GameStateManager::ChangeGameState(IGameState* gameState)
{
	while (!states.empty())
	{
		states.back()->Cleanup();
		states.pop_back();
	}

	states.push_back(gameState);
	states.back()->Init(GameStateManager::Instance());
}

void GameStateManager::PushGameState(IGameState* gameState)
{
	if (!states.empty())
	{
		states.back()->Pause();
	}

	states.push_back(gameState);
	states.back()->Init(GameStateManager::Instance());
}

void GameStateManager::PopState()
{
	if (!states.empty())
	{
		states.back()->Cleanup();
		states.pop_back();
	}

	if (!states.empty())
	{
		states.back()->Resume();
	}
}

void GameStateManager::HandleEvents()
{
	SDL_Event mainEvent;

	while (SDL_PollEvent(&mainEvent))
	{
		switch (mainEvent.type)
		{
		case SDL_QUIT:
			this->m_running = false;
			break;
		case SDL_KEYDOWN:
			switch (mainEvent.key.keysym.sym)
			{
			case SDLK_TAB:
				GameStateManager::Instance()->showFps = !GameStateManager::Instance()->showFps;
				break;
			default:
				states.back()->HandleEvents(mainEvent);
				break;
			}
			break;
		case SDL_KEYUP:
			//states.back()->handleEvents(mainEvent);
			break;
		default:
			// More likly to do nothing
			//states.back()->handleEvents(mainEvent);
			break;
		}
	}
}

void GameStateManager::FlushEvents()
{
	SDL_Event mainEvent;
	while (SDL_PollEvent(&mainEvent))
	{
		SDL_FlushEvent(SDL_MOUSEBUTTONDOWN);
		SDL_FlushEvent(SDL_MOUSEMOTION);
		SDL_FlushEvent(SDL_MOUSEWHEEL);
		SDL_FlushEvent(SDL_KEYDOWN);
		SDL_FlushEvent(SDL_KEYUP);
		SDL_FlushEvent(SDL_QUIT);
	}
}

void GameStateManager::Update(double dt)
{
	//OPTION ONE: update all GameStates
	for (size_t i = 0; i < states.size(); i++)
	{
		states.at(i)->Update(dt);
	}
}

void GameStateManager::Draw()
{
	//Clear Screen
	GameStateManager::Instance()->sdlInitializer->ClearScreen();

	//OPTION ONE: Draw all GameStates
	for (size_t i = 0; i < states.size(); i++)
	{
		states.at(i)->Draw();
	}

	//Draw entire screen
	GameStateManager::Instance()->sdlInitializer->DrawScreen();
}

Level* GameStateManager::GetLevel()
{
	// TODO: get current level
	return PlayState::Instance()->GetCurrentLevel();
}

void GameStateManager::QuitGame()
{
	this->m_running = false;
}

bool GameStateManager::Running()
{
	return m_running;
}

void GameStateManager::Quit()
{
	m_running = false;
	IMG_Quit();
	SDL_Quit();
}

void GameStateManager::Cleanup()
{
	//While there are states on the stack, clean them up
	while (!states.empty())
	{
		//Peek at top state and clean that state
		states.back()->Cleanup();

		//Remove top state
		states.pop_back();
	}

	delete this->sdlInitializer;
}

GameStateManager::~GameStateManager()
{
	delete sdlInitializer;
}
