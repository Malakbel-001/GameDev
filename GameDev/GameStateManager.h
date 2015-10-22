#pragma once

#include <SDL.h>
#include <vector>
#include "SDLInitializer.h"

class IGameState;


#include "Level.h"
#include "LevelFactory.h"

class GameStateManager
{
private:
	float updateLength;
	int fps;
	std::vector<IGameState*> states;
	IGameState* currentState;
	bool m_running;

	static GameStateManager m_Gsm;

public:
	bool showFps;
	GameStateManager();

	SDLInitializer* sdlInitializer;

	void init(const char* title, int width, int height, bool fullscreen);
	void cleanup();

	void setFps(int fps);
	int getFps();

	void changeGameState(IGameState* gameState);
	void pushGameState(IGameState* gameState);
	void popState();

	void update(double delta);
	void handleEvents();
	void flushEvents();
	void draw();

	void setUpdateLength(float updateLength);
	float getUpdateLength();

	void quitGame();
	bool running();
	void quit();

	static GameStateManager* Instance()
	{
		return &m_Gsm;
	};

	virtual ~GameStateManager();
	Level* GetLevel();
private:
	Level* currentLevel;

};
