#pragma once
#include "MenuBase.h"
#include "LTexture.h"
#include <Windows.h>
#include "EditorState.h"
class MenuState;
class LevelEditorMenu : public MenuBase
{
private:
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

	SDL_Rect pos[5];

	SDL_Color textColor;
	SDL_Color hoverTextColor;

	TTF_Font* titleFont;
	TTF_Font* textFont;

	SDL_Rect backToMainRect;
	SDL_Rect editorTitleRect;
	SDL_Rect newLevelRect;
	SDL_Rect OpenRect;
	SDL_Rect inputRect;

	SDL_Texture* backToMainTexture;
	SDL_Texture* editorTitleTexture;
	SDL_Texture* newLevelTexture;
	SDL_Texture* openTexture;
	SDL_Texture* inputTexture;

	Uint32 lockButtonTicks;
	std::string text;
public:
	LevelEditorMenu(MenuState*, SDL_Renderer*, TTF_Font*, TTF_Font*);
	void Init();

	void MakeBackToMain(SDL_Color);
	void MakeEditorTitle(SDL_Color);
	void MakeNewLevel(SDL_Color);
	void MakeOpen(SDL_Color);
	void MakeInput(SDL_Color);

	SDL_Texture* SurfaceToTexture(SDL_Surface*);

	void Highlight(int);

	void SetupRenderer();

	void Draw();

	void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
	void HandleTextInputEvents(SDL_Event event);
	void HandleMouseEvents(SDL_Event mainEvent);
	void Update(float dt);
	~LevelEditorMenu();
};

