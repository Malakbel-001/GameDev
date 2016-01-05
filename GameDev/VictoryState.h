#pragma once
#include "IGameState.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <iostream>
#include "SoundBank.h"
#include "Playstate.h"
#include "MenuState.h"
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

	// Stuff for text rendering
	TTF_Font* titleFont;
	TTF_Font* textFont;

#pragma region textures
	SDL_Texture* nextTexture;
	SDL_Texture* quitTexture; //2
	SDL_Texture* victoryTitleTexture; //3
	SDL_Texture* scoreTexture;
#pragma endregion textures

#pragma region rects
	//mainmenu
	SDL_Rect quitRect;
	SDL_Rect nextRect;
	SDL_Rect victoryTitleRect;
	SDL_Rect scoreRect;
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
	void Draw(float);
	void Background();

	virtual ~VictoryState();

	void Highlight(int);
	void MakeNextLevelText(SDL_Color);
	void MakeQuitText(SDL_Color);
	void MakeVictorytitle(SDL_Color);
	void MakeScoreText(SDL_Color);

private:
	SDL_Color textColor;
	SDL_Color hoverTextColor;
	const int renderItems = 4;
	vector<SDL_Rect> pos;
	int hoverX;
	int hoverY;
	int score;

	ParallaxBackground* parallaxBackground;
};
