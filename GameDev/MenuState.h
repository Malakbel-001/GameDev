#pragma once
#include "IGameState.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <iostream>
#include "PlayState.h"
#include "SoundBank.h"
class MenuState :
	public IGameState
{
private:
	int hoverX;
	int hoverY;
	int selectedCounter;
public:
	MenuState();
	GameStateManager* gsm;

	void MakePlayText(SDL_Color);
	void MakeHelpText(SDL_Color);
	void MakeQuitText(SDL_Color);
	void MakeCreditText(SDL_Color);
	void MakeBackToMainText(SDL_Color);
	void MakeCredits(SDL_Color);
	void MakeHelp(SDL_Color);

	void MakeMainTitle(SDL_Color);
	void MakeHelpTitle(SDL_Color);
	void MakeCreditsTitle(SDL_Color);

	void Highlight(int);



	// Setup
	bool InitEverything();
	bool InitSDL();
	//bool CreateRenderer();
	void SetupRenderer();
	//void HandleInput();
	void CreateHelpMenu();
	void loadMainMenu();
	void loadHelpMenu();
	void LoadCreditMenu();
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
	SDL_Texture* playTexture; //0
	SDL_Texture* helpTexture; //1
	SDL_Texture* quitTexture; //2
	SDL_Texture* mainTitleTexture; //3
	SDL_Texture* creditTexture; //9

	//helpMenu
	SDL_Texture* helpTitleTexture; //4
	SDL_Texture* helpTextTexture; //5
	SDL_Texture* backToMainTexture; //6

	//creditmenu
	SDL_Texture* creditTextTexture; //7
	SDL_Texture* creditTitleTexture; //8
#pragma endregion textures

#pragma region rects
	//mainmenu
	SDL_Rect solidRect;
	SDL_Rect blendedRect;
	SDL_Rect shadedRect;
	SDL_Rect mainTitleRect;
	SDL_Rect creditRect;
	//helpmenu
	SDL_Rect helpTitleRect;
	SDL_Rect helpTextRect;
	SDL_Rect backToMainRect;
	//creditmenu
	SDL_Rect creditTextRect;
	SDL_Rect creditTitleRect;
#pragma endregion rects

	SDL_Renderer* renderer;

	bool quit = false;

	enum State{ mainMenu, helpMenu, creditMenu };
	State menuState;
	
	void Init(GameStateManager *gsm);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
	void HandleMouseEvents(SDL_Event mainEvent);
	void Update(float dt);
	void Draw();
	void Background();

	virtual ~MenuState();

	//temp
	LTexture background;
	//background
	SDL_Rect backgroundRect;
	//background
	SDL_Texture* backgroundTexture;
};
