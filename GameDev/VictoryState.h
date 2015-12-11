#pragma once
#include "IGameState.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <iostream>
#include "SoundBank.h"
#include "Playstate.h"
class VictoryState :
	public IGameState
{
public:
	VictoryState();
	

	// Setup
	bool InitEverything();
	bool InitSDL();
	void SetupRenderer();
	bool CreateRenderer();

	// Our new function for setting uo SDL_TTF
	bool SetupTTF(const std::string &fontName, const std::string &fontName2);
	SDL_Texture* SurfaceToTexture(SDL_Surface* surf);
	void CreateTextTextures();

	// Stuff for text rendering
	TTF_Font* titleFont;
	TTF_Font* textFont;

#pragma region textures
	SDL_Texture* nextTexture;
	SDL_Texture* quitTexture; //2
	SDL_Texture* victoryTitleTexture; //3
#pragma endregion textures

#pragma region rects
	//mainmenu
	SDL_Rect quitRect;
	SDL_Rect nextRect;
	SDL_Rect victoryTitleRect;
#pragma endregion rects

	SDL_Renderer* renderer;

	bool quit = false;

	void Init(GameStateManager *gsm);
	void Cleanup();

	void Resume();
	void Pause();
	void Quit();
	void Next();
	void loadQuitMenu();

	void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
	void HandleMouseEvents(SDL_Event mainEvent);
	void Update(float);
	void Draw();
	void Move(float dt);
	void Background();

	virtual ~VictoryState();

	//temp
	LTexture background;
	//background
	SDL_Rect backgroundRect;
	//background
	SDL_Texture* backgroundTexture;

private:
	SDL_Color textColor;
	const int renderItems = 3;
	vector<SDL_Rect> pos;
};
