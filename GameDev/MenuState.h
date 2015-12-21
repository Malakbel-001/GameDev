#pragma once
#include "IGameState.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <iostream>
#include "PlayState.h"
#include "SoundBank.h"
#include "MenuBase.h"
#include "ParallaxBackground.h"
//#include "HelpMenu.h"
#include "SettingsConfig.h"
class MainMenu;
class HelpMenu;
class CreditMenu;
class OptionMenu;
class PlayMenu;

class MenuState :
	public IGameState
{
private:
	int hoverX;
	int hoverY;
	int selectedCounter;
	MenuBase* currentMenu;
	MenuBase* PreviousMenu;
	MainMenu* mainMenu;
	HelpMenu* helpMenu;
	CreditMenu* creditMenu;
	OptionMenu* optionMenu;
	PlayMenu* playMenu;

	ParallaxBackground* parallaxBackground;
	
public:
	MenuState();
	

	void Highlight(int);

	// Setup
	bool InitEverything();
	bool InitSDL();
	void SetupRenderer();
	void CreateHelpMenu();
	bool CreateRenderer();

	// Our new function for setting uo SDL_TTF
	bool SetupTTF(const std::string &fontName, const std::string &fontName2);
	SDL_Texture* SurfaceToTexture(SDL_Surface* surf);

	// Stuff for text rendering
	TTF_Font* titleFont;
	TTF_Font* textFont;
	
	SDL_Renderer* renderer;

	bool quit = false;
		
	void Init(GameStateManager *gsm);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
	void HandleMouseEvents(SDL_Event mainEvent);
	void Update(float);
	void Draw(float);
	void Background();

	virtual ~MenuState();
	
	void updateMenu(MenuEnum);
	
private:
	SDL_Color textColor;
	const int renderItems = 20;
	vector<SDL_Rect> pos;
};
