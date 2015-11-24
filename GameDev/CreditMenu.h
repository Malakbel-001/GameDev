#include "MenuBase.h"
#include "LTexture.h"
class MenuState;
class PauseState;
class CreditMenu : public MenuBase
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
	SDL_Rect creditTextRect;
	SDL_Rect creditTitleRect;

	SDL_Texture* backToMainTexture; //0
	SDL_Texture* creditTextTexture; //1
	SDL_Texture* helpCreditTexture; //2
public:
	CreditMenu(MenuState*, SDL_Renderer*, TTF_Font*, TTF_Font*);
	CreditMenu(PauseState*, SDL_Renderer*, TTF_Font*, TTF_Font*);
	void Init();
	~CreditMenu();

	void MakeBackToMain(SDL_Color);
	void MakeCreditText(SDL_Color);
	void MakeCreditTitle(SDL_Color);
	SDL_Texture* SurfaceToTexture(SDL_Surface*);

	void Highlight(int);

	void SetupRenderer();

	void Draw();

	void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
	void HandleMouseEvents(SDL_Event mainEvent);
	void Update(float dt);
};