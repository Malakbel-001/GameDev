#pragma once
#include "IGameState.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <iostream>
#include "SoundBank.h"
#include "MenuState.h"
#include "HighscoreConfig.h"
class GameOverState :
	public IGameState
{
public:
	GameOverState();

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
	SDL_Texture* scoreTexture;
	SDL_Texture* timeTexture;
	SDL_Texture* inputTexture;
	SDL_Texture* saveTexture;
	SDL_Texture* saveTextTexture;
#pragma endregion textures

#pragma region rects
	//mainmenu
	SDL_Rect quitRect;
	SDL_Rect gameoverTitleRect;
	SDL_Rect scoreRect;
	SDL_Rect timeRect;
	SDL_Rect inputRect;
	SDL_Rect saveRect;
	SDL_Rect saveTextRect;
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
	void HandleTextInputEvents(SDL_Event event);
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
	void MakeScoreText(SDL_Color);
	void MakeTimeText(SDL_Color);
	void MakeInputText(SDL_Color);
	void MakeSave(SDL_Color);
	void MakeSaveText(SDL_Color);
private:
	SDL_Color textColor;
	SDL_Color hoverTextColor;
	const int renderItems = 7;
	vector<SDL_Rect> pos;
	int hoverX;
	int hoverY;
	int score;
	vector<Uint32> time;
	string text;
	HighscoreConfig highscoreConfig;
};
