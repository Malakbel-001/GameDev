#pragma once
#include "IGameState.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <iostream>
#include "SoundBank.h"
class GameOverState :
	public IGameState
{
public:
	GameOverState();
	GameStateManager* gsm;

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
	SDL_Texture* quitTexture; //2
	SDL_Texture* gameoverTitleTexture; //3
#pragma endregion textures

#pragma region rects
	//mainmenu
	SDL_Rect quitRect;
	SDL_Rect gameoverTitleRect;
#pragma endregion rects

	SDL_Renderer* renderer;

	bool quit = false;
	
	void Init(GameStateManager *gsm);
	void Cleanup();

	void Resume();
	void Pause();
	void Quit();
	void loadQuitMenu();

	void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
	void HandleMouseEvents(SDL_Event mainEvent);
	void Update(float);
	void Draw();
	void Background();

	virtual ~GameOverState();

	//temp
	LTexture background;
	//background
	SDL_Rect backgroundRect;
	//background
	SDL_Texture* backgroundTexture;
	void Highlight(int);
	void MakeBackToMainText(SDL_Color);
	void MakeGameOverTitle(SDL_Color);
private:
	SDL_Color textColor;
	SDL_Color hoverTextColor;
	const int renderItems = 18;
	vector<SDL_Rect> pos;
	int hoverX;
	int hoverY;
};
