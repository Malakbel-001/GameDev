#pragma once
#include "IGameState.h"
class MenuState :
	public IGameState
{
public:
	MenuState();
	GameStateManager* gsm;

	void Init(GameStateManager *gsm);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(SDL_Event mainEvent);
	void Update(float dt);
	void Draw();

	virtual ~MenuState();
};

