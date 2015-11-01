#pragma once
#include "GameStateManager.h"

class IGameState
{
protected:
	IGameState() { }
public:

	virtual void Init(GameStateManager *gsm) = 0;
	virtual void Cleanup() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents(SDL_Event mainEvent) = 0;
	virtual void Update(double dt) = 0;
	virtual void Draw() = 0;

	void ChangeState(GameStateManager* gsm, IGameState* state)
	{
		gsm->ChangeGameState(state);
	}

	virtual ~IGameState();
};
