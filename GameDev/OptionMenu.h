#pragma once
#include "MenuBase.h"
#include "LTexture.h"
#include "SettingsConfig.h"
#include "ParallaxBackground.h"
class MenuState;
class PauseState;
class OptionMenu : public MenuBase
{
private:
	Uint32 flags;
	SettingsConfig settingsConfig;
	int hoverX;
	int hoverY;
	int selectedCounter;
	SDL_Renderer* renderer;
	MenuState* mainMenu;
	PauseState* pauseMenu;

	//temp
	LTexture background;
	//background
	SDL_Rect backgroundRect;
	//background
	SDL_Texture* backgroundTexture;

	SDL_Rect pos[8];

	SDL_Color textColor;
	SDL_Color hoverTextColor;

	TTF_Font* titleFont;
	TTF_Font* textFont;

	SDL_Rect backToMainRect;
	SDL_Rect optionsTitleRect;
	SDL_Rect sfxOnRect;
	SDL_Rect sfxOffRect;
	SDL_Rect musicOnRect;
	SDL_Rect musicOffRect;
	SDL_Rect fullScreenOnRect;
	SDL_Rect fullScreenOffRect;

	SDL_Texture* backToMainTexture; //0
	SDL_Texture* optionsTitleTexture; //15
	SDL_Texture* sfxOnTexture; //11
	SDL_Texture* sfxOffTexture; //12
	SDL_Texture* musicOnTexture; //13
	SDL_Texture* musicOffTexture; //14
	SDL_Texture* fullScreenOnTexture; //16
	SDL_Texture* fullScreenOffTexture; //16

private:
	ParallaxBackground* parallaxBackground;

	void InitClass(SDL_Renderer*, TTF_Font*, TTF_Font*, ParallaxBackground*);

public:
	void LoadSettings(map<string, bool>);
	OptionMenu(MenuState*, SDL_Renderer*, TTF_Font*, TTF_Font*, ParallaxBackground*);
	OptionMenu(PauseState*, SDL_Renderer*, TTF_Font*, TTF_Font*, ParallaxBackground*);
	~OptionMenu();

	void Init();
	void MakeBackToMain(SDL_Color);
	void MakeOptionText(SDL_Color);
	void MakeSfxOn(SDL_Color);
	void MakeSfxOff(SDL_Color);
	void MakeMusicOn(SDL_Color);
	void MakeMusicOff(SDL_Color);
	void MakeFullScreenOn(SDL_Color);
	void MakeFullScreenOff(SDL_Color);
	void MakeOptionTitle(SDL_Color);
	SDL_Texture* SurfaceToTexture(SDL_Surface*);

	void Highlight(int);

	void SetupRenderer();

	void Draw();

	void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
	void HandleTextInputEvents(SDL_Event event);
	void HandleMouseEvents(SDL_Event mainEvent);
	void Update(float dt);

};