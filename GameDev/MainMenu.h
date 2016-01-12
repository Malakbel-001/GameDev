#include "MenuBase.h"
#include "LTexture.h"
#include <Windows.h>
class MenuState;
class MainMenu : public MenuBase
{
private:
	int hoverX;
	int hoverY;
	int selectedCounter;
	SDL_Renderer* renderer;
	MenuState* menu;

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

	SDL_Rect solidRect;
	SDL_Rect editorRect;
	SDL_Rect blendedRect;
	SDL_Rect shadedRect;
	SDL_Rect mainTitleRect;
	SDL_Rect creditRect;
	SDL_Rect optionsRect;
	SDL_Rect highscoreRect;

	SDL_Texture* playTexture;
	SDL_Texture* editorTexture;
	SDL_Texture* helpTexture;
	SDL_Texture* quitTexture;
	SDL_Texture* mainTitleTexture;
	SDL_Texture* creditTexture;
	SDL_Texture* optionsTexture;
	SDL_Texture* highscoreTexture;
public:
	MainMenu(MenuState*, SDL_Renderer*, TTF_Font*, TTF_Font*);
	void Init();
	~MainMenu();
	
	void MakePlayText(SDL_Color);
	void MakeLevelEditorText(SDL_Color);
	void MakeHelpText(SDL_Color);
	void MakeQuitText(SDL_Color);
	void MakeCreditText(SDL_Color);
	void MakeOptionText(SDL_Color);
	void MakeMainTitle(SDL_Color);
	void MakeHighscoreText(SDL_Color);
	SDL_Texture* SurfaceToTexture(SDL_Surface*);

	void Highlight(int);

	void SetupRenderer();

	void Draw();

	void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
	void HandleTextInputEvents(SDL_Event event);
	void HandleMouseEvents(SDL_Event mainEvent);
	void Update(float dt);
};