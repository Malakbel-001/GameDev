#pragma once
#include "IGameState.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <iostream>
#include "PlayState.h"
#include "SoundBank.h"
#include "MenuBase.h"
#include "MenuState.h"
//#include "HelpMenu.h"
class PauseMenu;
class HelpMenu;
class CreditMenu;
class OptionMenu;
class PauseState :
	public IGameState
{
private:
	int hoverX;
	int hoverY;
	int selectedCounter;
	MenuBase* currentMenu;
	MenuBase* PreviousMenu;
	PauseMenu* pauseMenu;
	HelpMenu* helpMenu;
	CreditMenu* creditMenu;
	OptionMenu* optionMenu;

	ParallaxBackground* parallaxBackground;

public:
	
	


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

	void MakeOptionText(SDL_Color);
	void MakeSfxOn(SDL_Color);
	void MakeSfxOff(SDL_Color);
	void MakeMusicOn(SDL_Color);
	void MakeMusicOff(SDL_Color);
	void MakeFullScreenOn(SDL_Color);
	void MakeFullScreenOff(SDL_Color);
	void MakeOptionTitle(SDL_Color);

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
	void LoadOptionsMenu();
	bool CreateRenderer();

	// Our new function for setting uo SDL_TTF
	bool SetupTTF(const std::string &fontName, const std::string &fontName2);
	SDL_Texture* SurfaceToTexture(SDL_Surface* surf);
	//void CreateTextTextures();

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
	SDL_Texture* optionsTexture;

	//helpMenu
	SDL_Texture* helpTitleTexture; //4
	SDL_Texture* helpTextTexture; //5
	SDL_Texture* backToMainTexture; //6

	//creditmenu
	SDL_Texture* creditTextTexture; //7
	SDL_Texture* creditTitleTexture; //8

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
	SDL_Rect mainTitleRect;
	SDL_Rect creditRect;
	SDL_Rect optionsRect;
	//helpmenu
	SDL_Rect helpTitleRect;
	SDL_Rect helpTextRect;
	SDL_Rect backToMainRect;
	//creditmenu
	SDL_Rect creditTextRect;
	SDL_Rect creditTitleRect;
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

	//enum State{ mainMenu, helpMenu, creditMenu, optionsMenu };
	//State menuState;

	void Init(GameStateManager *gsm);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
	void HandleMouseEvents(SDL_Event mainEvent);
	void HandleTextInputEvents(SDL_Event event);
	void Move(float dt);
	void Update(float dt, float manipulatorSpeed);
	void Draw(float dt, float manipulatorSpeed);
	void Background();

	virtual ~PauseState();

	void updateMenu(MenuEnum);

};
