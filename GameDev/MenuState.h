#pragma once
#include "IGameState.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <iostream>
#include "PlayState.h"
#include "SoundBank.h"
class MenuState :
	public IGameState
{
public:
	MenuState();
	GameStateManager* gsm;
	
	void RunGame();
	void Init(GameStateManager *gsm);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(SDL_Event mainEvent);
	/*test*/void HandleEvents();
	void Update(float dt);
	void Draw(SDL_Renderer*  sdl);

	virtual ~MenuState();
};

