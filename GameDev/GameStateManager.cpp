#include "GameStateManager.h"
#include "IGameState.h"
#include "MenuState.h"
#include "PlayState.h"
#include <iostream>
#include <Windows.h>

GameStateManager GameStateManager::m_Gsm;
GameStateManager::GameStateManager() { }

void GameStateManager::init(const char* title, int width, int height, bool fullscreen)
{
	sdlInitializer = new SDLInitializer();
	sdlInitializer->init(title, width, height, fullscreen);

	m_running = true;
	showFps = false;

	GameStateManager::Instance()->setFps(0);
	this->updateLength = 0;

	GameStateManager::Instance()->changeGameState(PlayState::Instance());
}

void GameStateManager::setUpdateLength(float updateLength)
{
	this->updateLength = updateLength;
}

void GameStateManager::setFps(int fps)
{
	GameStateManager::Instance()->fps = fps;
}

int GameStateManager::getFps()
{
	return GameStateManager::Instance()->fps;
}

void GameStateManager::changeGameState(IGameState* gameState)
{
	while (!states.empty())
	{
		states.back()->cleanup();
		states.pop_back();
	}

	states.push_back(gameState);
	states.back()->init(GameStateManager::Instance());
}

void GameStateManager::pushGameState(IGameState* gameState)
{
	if (!states.empty())
	{
		states.back()->pause();
	}

	states.push_back(gameState);
	states.back()->init(GameStateManager::Instance());
}

void GameStateManager::popState()
{
	if (!states.empty())
	{
		states.back()->cleanup();
		states.pop_back();
	}

	if (!states.empty())
	{
		states.back()->resume();
	}
}

void GameStateManager::handleEvents()
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
				states.back()->handleEvents(mainEvent);
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

void GameStateManager::flushEvents()
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

void GameStateManager::update(double dt)
{
	//OPTION ONE: update all GameStates
	for (size_t i = 0; i < states.size(); i++)
	{
		states.at(i)->update(dt);
	}
}

void GameStateManager::draw()
{
	//Clear Screen
	GameStateManager::Instance()->sdlInitializer->clearScreen();

	//OPTION ONE: Draw all GameStates
	for (size_t i = 0; i < states.size(); i++)
	{
		states.at(i)->draw();
	}

	//Draw entire screen
	GameStateManager::Instance()->sdlInitializer->drawScreen();
}

Level* GameStateManager::GetLevel()
{
	// TODO: get current level
	return PlayState::Instance()->getCurrentLevel();
}

void GameStateManager::quitGame()
{
	this->m_running = false;
}

bool GameStateManager::running()
{
	return m_running;
}

void GameStateManager::quit()
{
	m_running = false;
	IMG_Quit();
	SDL_Quit();
}

void GameStateManager::cleanup()
{
	//While there are states on the stack, clean them up
	while (!states.empty())
	{
		//Peek at top state and clean that state
		states.back()->cleanup();

		//Remove top state
		states.pop_back();
	}

	delete this->sdlInitializer;
}

GameStateManager::~GameStateManager()
{
	delete sdlInitializer;
}
