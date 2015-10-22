#pragma once
#include "LevelStateManager.h"
#include "Level.h"

class ILevelState
{
public:
	ILevelState();

	virtual void init(LevelStateManager *lsm) = 0;
	virtual void cleanup() = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void handleEvents(SDL_Event mainEvent) = 0;
	virtual void update(double dt) = 0;
	virtual void draw() = 0;

	void ChangeState(LevelStateManager* lsm, ILevelState* state)
	{
		lsm->changeLevel(state);
	}

	virtual ~ILevelState();
};

