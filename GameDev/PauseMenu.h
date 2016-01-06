#include "MenuBase.h"
#include "LTexture.h"
class PauseState;
class PauseMenu : public MenuBase
{
private:
	int hoverX;
	int hoverY;
	int selectedCounter;
	SDL_Renderer* renderer;
	PauseState* menu;

	//temp
	LTexture background;
	//background
	SDL_Rect backgroundRect;
	//background
	SDL_Texture* backgroundTexture;

	SDL_Rect pos[6];

	SDL_Color textColor;
	SDL_Color hoverTextColor;

	TTF_Font* titleFont;
	TTF_Font* textFont;

	SDL_Rect solidRect;
	SDL_Rect blendedRect;
	SDL_Rect shadedRect;
	SDL_Rect mainTitleRect;
	SDL_Rect creditRect;
	SDL_Rect optionsRect;

	SDL_Texture* playTexture; //0
	SDL_Texture* helpTexture; //1
	SDL_Texture* quitTexture; //2
	SDL_Texture* mainTitleTexture; //3
	SDL_Texture* creditTexture; //9
	SDL_Texture* optionsTexture;
public:
	PauseMenu(PauseState*, SDL_Renderer*, TTF_Font*, TTF_Font*);
	void Init();
	~PauseMenu();

	void MakePlayText(SDL_Color);
	void MakeHelpText(SDL_Color);
	void MakeQuitText(SDL_Color);
	void MakeCreditText(SDL_Color);
	void MakeOptionText(SDL_Color);
	void MakeMainTitle(SDL_Color);
	SDL_Texture* SurfaceToTexture(SDL_Surface*);

	void Highlight(int);

	void SetupRenderer();

	void Draw();

	void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
	void HandleMouseEvents(SDL_Event mainEvent);
	void Update(float dt);
};