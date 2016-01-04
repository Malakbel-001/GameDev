#pragma once
#include "IGameState.h"
#include "GameStateManager.h"
#include "SoundBank.h"
#include <thread>
#include "SDL_ttf.h"

class LoadState : public IGameState {
private:
	
	SDL_Renderer* renderer;

	DrawableContainer* drawableContainer;
	IGameState* playState;
	BareEntity* bare;

	TTF_Font* textFont;

	SDL_Texture* loadingTexture;
	SDL_Texture* finishedTexture;
	SDL_Rect loadingRect;
	SDL_Rect finishedRect;

	LTexture advertisementPic; //picture, jpg, png, etc. Look at LTexture and Advertisement() for more details
	SDL_Rect advertisementRect;

	//temp
	LTexture background;
	//background
	SDL_Rect backgroundRect;
	//background
	SDL_Texture* backgroundTexture;

	int levelToLoad;
public:
	LoadState(int lvl);
	virtual ~LoadState();
	bool loadedPlay;
	void LoadPlayState();
	void Init(GameStateManager* gsm);
	void Cleanup();
	void Advertisement(char* path);

	void Pause();
	void Resume();

	void HandleMouseEvents(SDL_Event mainEvent);
	void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
	void Update(float dt, float manipulatorSpeed);
	void Draw(float dt, float manipulatorSpeed);
};