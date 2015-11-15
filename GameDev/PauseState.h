#pragma once
#include "IGameState.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <iostream>
#include "SoundBank.h"
class PauseState :
	public IGameState
{
public:
	PauseState();
	GameStateManager* gsm;

	// Setup
	bool InitEverything();
	bool InitSDL();
	//bool CreateRenderer();
	void SetupRenderer();
	//void HandleInput();
	void CreateHelpMenu();
	void loadPauseMenu();
	void loadHelpMenu();
	void LoadOptionsMenu();
	bool CreateRenderer();

	// Our new function for setting uo SDL_TTF
	bool SetupTTF(const std::string &fontName, const std::string &fontName2);
	SDL_Texture* SurfaceToTexture(SDL_Surface* surf);
	void CreateTextTextures();

	// Stuff for text rendering
	TTF_Font* titleFont;
	TTF_Font* textFont;

#pragma region textures
	//mainMenu
	SDL_Texture* resumeTexture; //0
	SDL_Texture* helpTexture; //1
	SDL_Texture* quitTexture; //2
	SDL_Texture* pauseTitleTexture; //3
	SDL_Texture* optionsTexture;

	//helpMenu
	SDL_Texture* helpTitleTexture; //4
	SDL_Texture* helpTextTexture; //5
	SDL_Texture* backToPauseTexture; //6

	//optionsmenu
	SDL_Texture* optionsTitleTexture; //15
	SDL_Texture* sfxOnTexture; //11
	SDL_Texture* sfxOffTexture; //12
	SDL_Texture* musicOnTexture; //13
	SDL_Texture* musicOffTexture; //14
	SDL_Texture* fullScreenOnTexture; //16
	SDL_Texture* fullScreenOffTexture; //16
#pragma endregion textures

#pragma region rects
	//mainmenu
	SDL_Rect solidRect;
	SDL_Rect blendedRect;
	SDL_Rect shadedRect;
	SDL_Rect pauseTitleRect;
	SDL_Rect optionsRect;
	//helpmenu
	SDL_Rect helpTitleRect;
	SDL_Rect helpTextRect;
	SDL_Rect backToPauseRect;
	//optionsmenu
	SDL_Rect optionsTitleRect;
	SDL_Rect sfxOnRect;
	SDL_Rect sfxOffRect;
	SDL_Rect musicOnRect;
	SDL_Rect musicOffRect;
	SDL_Rect fullScreenOnRect;
	SDL_Rect fullScreenOffRect;
#pragma endregion rects

	SDL_Renderer* renderer;

	bool quit = false;

	enum State{ pauseMenu, helpMenu, optionsMenu };
	State menuState;

	void Init(GameStateManager *gsm);
	void Cleanup();

	void Pause();
	void Resume();
	void Quit();

	void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
	void HandleMouseEvents(SDL_Event mainEvent);
	void Update(float dt);
	void Draw();
	void Background();

	virtual ~PauseState();

	//temp
	LTexture background;
	//background
	SDL_Rect backgroundRect;
	//background
	SDL_Texture* backgroundTexture;

private:
	SDL_Color textColor;
	const int renderItems = 18;
	vector<SDL_Rect> pos;
};
