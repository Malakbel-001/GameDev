#pragma once
#include "IGameState.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>
#include <iostream>
#include "SoundBank.h"
#include "MenuState.h"
#include "EditorState.h"
class EditorSubState :
	public IGameState
{
public:
	EditorSubState();
	~EditorSubState();
	bool InitEverything();
	bool InitSDL();
	void SetupRenderer();
	bool CreateRenderer();

	// Our new function for setting uo SDL_TTF
	bool SetupTTF(const std::string &fontName, const std::string &fontName2);
	SDL_Texture* SurfaceToTexture(SDL_Surface* surf);
	void CreateTextTextures();
		

	void Init(GameStateManager *gsm);
	void Cleanup();

	void Resume();
	void Pause();
	void Quit();
	void loadQuitMenu();

	void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
	void HandleMouseEvents(SDL_Event mainEvent);
	void HandleTextInputEvents(SDL_Event event);
	void Move(float dt);
	void Update(float dt, float manipulatorSpeed);
	void Draw(float dt, float manipulatorSpeed);
	void Background();

	void Highlight(int);
	void MakeBackToEditorText(SDL_Color);
	void MakeSubMenuTitle(SDL_Color);
	void MakePlayText(SDL_Color);
	void MakeSaveSameText(SDL_Color);
	void MakeBackToMainText(SDL_Color);
private:
	SDL_Color textColor;
	SDL_Color hoverTextColor;
	const int renderItems = 7;
	vector<SDL_Rect> pos;
	int hoverX;
	int hoverY;

	ParallaxBackground* parallaxBackground;
	int score;
	vector<Uint32> time;
	string text;
	
	// Stuff for text rendering
	TTF_Font* titleFont;
	TTF_Font* textFont;

#pragma region textures
	SDL_Texture* quitTexture; //2
	SDL_Texture* gameoverTitleTexture; //3
	SDL_Texture* playTexture;
	SDL_Texture* saveSameTexture;
	SDL_Texture* backToMainTexture;
	SDL_Texture* inputTexture;
#pragma endregion textures

#pragma region rects
	//mainmenu
	SDL_Rect quitRect;
	SDL_Rect gameoverTitleRect;
	SDL_Rect playRect;
	SDL_Rect saveSameRect;
	SDL_Rect backToMainRect;
	SDL_Rect inputRect;
#pragma endregion rects

	SDL_Renderer* renderer;

	bool quit = false;
};

