#pragma once
#include "MenuBase.h"
#include "LTexture.h"
#include "LevelConfig.h"
class MenuState;
class PlayMenu : public MenuBase
{
private:
	map<string, bool>* levelsMap;
	LevelConfig levelconfig;
	int hoverX;
	int hoverY;
	int selectedCounter;
	SDL_Renderer* renderer;
	MenuState* mainMenu;

	LTexture background;
	//background
	SDL_Rect backgroundRect;
	//background
	SDL_Texture* backgroundTexture;

	SDL_Rect pos[6];

	SDL_Color textColor;
	SDL_Color hoverTextColor;
	SDL_Color diseabledTextColor;

	TTF_Font* titleFont;
	TTF_Font* textFont;

	SDL_Rect backToMainRect;
	SDL_Rect playTitleRect;
	SDL_Rect newGameRect;
	SDL_Rect level1Rect;
	SDL_Rect level2Rect;
	//SDL_Rect level3Rect;

	SDL_Texture* backToMainTexture;
	SDL_Texture* playTitleTexture;
	SDL_Texture* newGameTexture;
	SDL_Texture* level1Texture;
	SDL_Texture* level2Texture;
	//SDL_Texture* level3Texture;
public:
	PlayMenu(MenuState*, SDL_Renderer*, TTF_Font*, TTF_Font*);
	void LoadLevels();
	void Init();

	void MakeBackToMain(SDL_Color);
	void MakePlayTitle(SDL_Color);
	void MakeNewGame(SDL_Color);
	void MakeLevel1(SDL_Color);
	void MakeLevel2(SDL_Color);
	void MakeLevel3(SDL_Color);

	SDL_Texture* SurfaceToTexture(SDL_Surface*);

	void Highlight(int);

	void SetupRenderer();

	void Draw();

	void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
	void HandleMouseEvents(SDL_Event mainEvent);
	void Update(float dt);

	~PlayMenu();
};

