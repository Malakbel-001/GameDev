#pragma once
#include "IGameState.h"
class PauseState :
	public IGameState
{
public:
	PauseState();
	virtual ~PauseState();
};

