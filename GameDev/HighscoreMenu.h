#pragma once
#include "MenuBase.h"
#include "LTexture.h"
#include "HighscoreConfig.h"
class MenuState;
class HighscoreMenu : public MenuBase
{
private:
	vector<Score>* highscores;
	HighscoreConfig highscoreConfig;
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

	SDL_Rect pos[12];

	SDL_Color textColor;
	SDL_Color hoverTextColor;
	SDL_Color disabledTextColor;

	TTF_Font* titleFont;
	TTF_Font* textFont;

	SDL_Rect backToMainRect;
	SDL_Rect highscoreTitleRect;
	SDL_Rect score1Rect;
	SDL_Rect score2Rect;
	SDL_Rect score3Rect;
	SDL_Rect score4Rect;
	SDL_Rect score5Rect;
	SDL_Rect score6Rect;
	SDL_Rect score7Rect;
	SDL_Rect score8Rect;
	SDL_Rect score9Rect;
	SDL_Rect score10Rect;

	SDL_Texture* backToMainTexture;
	SDL_Texture* highscoreTitleTexture;
	SDL_Texture* score1Texture;
	SDL_Texture* score2Texture;
	SDL_Texture* score3Texture;
	SDL_Texture* score4Texture;
	SDL_Texture* score5Texture;
	SDL_Texture* score6Texture;
	SDL_Texture* score7Texture;
	SDL_Texture* score8Texture;
	SDL_Texture* score9Texture;
	SDL_Texture* score10Texture;
public:
	HighscoreMenu(MenuState*, SDL_Renderer*, TTF_Font*, TTF_Font*);
	void LoadScores();
	void Init();

	void MakeBackToMain(SDL_Color);
	void MakeHighscoreTitle(SDL_Color);
	void MakeScore1(SDL_Color);
	void MakeScore2(SDL_Color);
	void MakeScore3(SDL_Color);
	void MakeScore4(SDL_Color);
	void MakeScore5(SDL_Color);
	void MakeScore6(SDL_Color);
	void MakeScore7(SDL_Color);
	void MakeScore8(SDL_Color);
	void MakeScore9(SDL_Color);
	void MakeScore10(SDL_Color);
	void UpdateScore();

	SDL_Texture* SurfaceToTexture(SDL_Surface*);

	void Highlight(int);

	void SetupRenderer();

	void Draw();

	void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
	void HandleTextInputEvents(SDL_Event event);
	void HandleMouseEvents(SDL_Event mainEvent);
	void Update(float dt);

	string GetScores(int);
	vector<Score>* SortScoreByScore();
	~HighscoreMenu();
};

