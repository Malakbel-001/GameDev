#pragma once
#include "IGameState.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <iostream>
class MenuState : public IGameState
{
private:
	static MenuState m_MenuState;
public:
	MenuState();
	virtual ~MenuState();
	static MenuState* Instance() { return &m_MenuState; };
};

