#include "MenuBase.h"
#include "LTexture.h"
class MenuState;
class PauseState;
class HelpMenu : public MenuBase
{
private:
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

	SDL_Rect pos[3];

	SDL_Color textColor;
	SDL_Color hoverTextColor;

	TTF_Font* titleFont;
	TTF_Font* textFont;

	SDL_Rect backToMainRect;
	SDL_Rect helpTextRect;
	SDL_Rect helpTitleRect;

	SDL_Texture* backToMainTexture; //0
	SDL_Texture* helpTextTexture; //1
	SDL_Texture* helpTitleTexture; //2
public:
	HelpMenu(MenuState*, SDL_Renderer*, TTF_Font*, TTF_Font*);
	HelpMenu(PauseState*, SDL_Renderer*, TTF_Font*, TTF_Font*);
	void Init();
	~HelpMenu();

	void MakeBackToMain(SDL_Color);
	void MakeHelpText(SDL_Color);
	void MakeHelpTitle(SDL_Color);
	SDL_Texture* SurfaceToTexture(SDL_Surface*);

	void Highlight(int);

	void SetupRenderer();

	void Draw();

	void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
	void HandleTextInputEvents(SDL_Event event);
	void HandleMouseEvents(SDL_Event mainEvent);
	void Update(float dt);
};