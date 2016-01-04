#pragma once
#include <unordered_map>
#include "IGameState.h"
#include <SDL_events.h>
#include "GameStateManager.h"
class IGameState
{
protected:
	GameStateManager* gsm;

public:
	IGameState(){};
	virtual void Init(GameStateManager *gsm) = 0;
	virtual void Cleanup() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleMouseEvents(SDL_Event mainEvent) = 0;
	virtual void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events) = 0;
	virtual void Update(float dt, float manipulatorSpeed) = 0;
	virtual void Draw(float dt, float manipulatorSpeed) = 0;
	void ChangeState(GameStateManager* gsm, IGameState* state)
	{
		gsm->PopState();
	}

	GameStateManager* GetGSM();

	virtual ~IGameState();
	
};

