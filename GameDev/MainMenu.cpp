/*#include "MainMenu.h"

// Setup
bool InitEverything();
bool InitSDL();
bool CreateWindow();
bool CreateRenderer();
void SetupRenderer();
void HandleInput();
void CreateHelpMenu();
void loadMainMenu();
void loadHelpMenu();
void LoadCreditMenu();

// Our new function for setting uo SDL_TTF
bool SetupTTF(const std::string &fontName);
SDL_Texture* SurfaceToTexture(SDL_Surface* surf);
void CreateTextTextures();

// Update ( happens every frame )
void Render();
void RunGame();

// Stuff for text rendering
TTF_Font* titleFont;
TTF_Font* textFont;
SDL_Color textColor = { 255, 255, 255, 255 }; // white
SDL_Color backgroundColor = { 0, 0, 0, 255 }; // black

const int renderItems = 10;
SDL_Rect pos[renderItems];
#pragma region textures
//mainMenu
SDL_Texture* playTexture; //0
SDL_Texture* helpTexture; //1
SDL_Texture* quitTexture; //2
SDL_Texture* mainTitleTexture; //3
SDL_Texture* creditTexture; //9

//helpMenu
SDL_Texture* helpTitleTexture; //4
SDL_Texture* helpTextTexture; //5
SDL_Texture* backToMainTexture; //6

//creditmenu
SDL_Texture* creditTextTexture; //7
SDL_Texture* creditTitleTexture; //8
#pragma endregion textures

#pragma region rects
//mainmenu
SDL_Rect solidRect;
SDL_Rect blendedRect;
SDL_Rect shadedRect;
SDL_Rect mainTitleRect;
SDL_Rect creditRect;
//helpmenu
SDL_Rect helpTitleRect;
SDL_Rect helpTextRect;
SDL_Rect backToMainRect;
//creditmenu
SDL_Rect creditTextRect;
SDL_Rect creditTitleRect;
#pragma endregion rects

SDL_Rect windowRect = { 8, 30, 1200, 700 };
SDL_Window* window;
SDL_Renderer* renderer;

bool quit = false;

enum State{mainMenu, helpMenu, creditMenu};
State menuState;


MainMenu::MainMenu()
{
	if (!InitEverything()){
		std::cout << "-1";
	}
	menuState = mainMenu;
	RunGame();

	// Clean up font
	TTF_CloseFont(titleFont);
	TTF_CloseFont(textFont);
}

void RunGame()
{
	while (!quit){

		HandleInput();

		Render();
	}
	SDL_DestroyWindow(window);
}

void HandleInput(){
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_MOUSEBUTTONDOWN:
			int x = event.button.x;
			int y = event.button.y;
			for (int i = 0; i < renderItems; i++)
			{
				if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h){
					switch (i){
						//item 1, mainmenu play
					case 0:
						quit = true;
						break;
						//item 2, mainmenu help
					case 1:
						menuState = helpMenu;
						break;
						//item 3,mainmenu quit
					case 2:
						exit(0);
						break;
						//item 6, backto main
					case 6:
						menuState = mainMenu;
						break;
						//item 9, mainmenu credit
					case 9:
						menuState = creditMenu;
						break;
					}
				}
			}
			break;
		}
	}
}

void Render()
{
	SDL_RenderClear(renderer);
	switch (menuState){
		//mainmenu
	case mainMenu:
		loadMainMenu();
		break;
	//helpmenu
	case helpMenu:
		loadHelpMenu();
		break;
	case creditMenu:
		LoadCreditMenu();
		break;
	}
	SDL_RenderPresent(renderer);
}

void loadMainMenu(){
	SDL_RenderCopy(renderer, playTexture, nullptr, &solidRect);
	SDL_RenderCopy(renderer, helpTexture, nullptr, &blendedRect);
	SDL_RenderCopy(renderer, quitTexture, nullptr, &shadedRect);
	SDL_RenderCopy(renderer, creditTexture, nullptr, &creditRect);
	SDL_RenderCopy(renderer, mainTitleTexture, nullptr, &mainTitleRect);
}

void loadHelpMenu(){
	SDL_RenderCopy(renderer, helpTextTexture, nullptr, &helpTextRect);
	SDL_RenderCopy(renderer, helpTitleTexture, nullptr, &helpTitleRect);
	SDL_RenderCopy(renderer, backToMainTexture, nullptr, &backToMainRect);
}

void LoadCreditMenu(){
	SDL_RenderCopy(renderer, creditTextTexture, nullptr, &creditTextRect);
	SDL_RenderCopy(renderer, creditTitleTexture, nullptr, &creditTitleRect);
	SDL_RenderCopy(renderer, backToMainTexture, nullptr, &backToMainRect);
}

// Initialization ++
// ==================================================================
bool SetupTTF(const std::string &fontName, const std::string &fontName2)
{
	// SDL2_TTF needs to be initialized just like SDL2
	if (TTF_Init() == -1)
	{
		std::cout << " Failed to initialize TTF : " << TTF_GetError() << std::endl;
		return false;
	}

	// Load our fonts, with a huge size
	titleFont = TTF_OpenFont(fontName.c_str(), 90);
	textFont = TTF_OpenFont(fontName2.c_str(), 35);

	// Error check
	if (titleFont == nullptr)
	{
		std::cout << " Failed to load font : " << TTF_GetError() << std::endl;
		return false;
	}

	if (textFont == nullptr)
	{
		std::cout << " Failed to load font : " << TTF_GetError() << std::endl;
		return false;
	}

	return true;
}
void CreateTextTextures()
{
#pragma region play
	SDL_Surface* play = TTF_RenderText_Blended(textFont, "Play", textColor);
	playTexture = SurfaceToTexture(play);

	SDL_QueryTexture(playTexture, NULL, NULL, &solidRect.w, &solidRect.h);
	solidRect.x = 15;
	solidRect.y = 250;
	pos[0] = solidRect;
#pragma endregion play
#pragma region help
	SDL_Surface* help = TTF_RenderText_Blended(textFont, "Help", textColor);
	helpTexture = SurfaceToTexture(help);

	SDL_QueryTexture(helpTexture, NULL, NULL, &blendedRect.w, &blendedRect.h);
	blendedRect.x = 15;
	blendedRect.y = solidRect.y + solidRect.h + 20;
	pos[1] = blendedRect;
#pragma endregion help
#pragma region credit
		SDL_Surface* credit = TTF_RenderText_Blended(textFont, "Credits", textColor);
	creditTexture = SurfaceToTexture(credit);

	SDL_QueryTexture(creditTexture, NULL, NULL, &creditRect.w, &creditRect.h);
	creditRect.x = 15;
	creditRect.y = blendedRect.y + blendedRect.h + 20;;
	pos[9] = creditRect;
#pragma endregion credit
#pragma region quit
	SDL_Surface* quit = TTF_RenderText_Blended(textFont, "Quit", textColor);
	quitTexture = SurfaceToTexture(quit);

	SDL_QueryTexture(quitTexture, NULL, NULL, &shadedRect.w, &shadedRect.h);
	shadedRect.x = 15;
	shadedRect.y = creditRect.y + creditRect.h + 20;
	pos[2] = shadedRect;
#pragma endregion quit
#pragma region maintitle
	SDL_Surface* mainTitle = TTF_RenderText_Blended(titleFont, "Jark Hunt", textColor);
	mainTitleTexture = SurfaceToTexture(mainTitle);

	SDL_QueryTexture(mainTitleTexture, NULL, NULL, &mainTitleRect.w, &mainTitleRect.h);
	mainTitleRect.x = 375;
	mainTitleRect.y = 5;
	pos[3] = mainTitleRect;
#pragma endregion maintitle
#pragma region helptitle
	SDL_Surface* helpTitle = TTF_RenderText_Blended(titleFont, "Help", textColor);
	helpTitleTexture = SurfaceToTexture(helpTitle);

	SDL_QueryTexture(helpTitleTexture, NULL, NULL, &helpTitleRect.w, &helpTitleRect.h);
	helpTitleRect.x = 375;
	helpTitleRect.y = 5;
	pos[4] = helpTitleRect;
#pragma endregion helptitle
#pragma region helptext
	SDL_Surface* helpText = TTF_RenderText_Blended_Wrapped(textFont, "Dit is een help menu. Hierin wordt beschreven hoe het spel werkt en wat het doel is en eventuele extra informatie die nu nog niet bekend is maar het is gewoon een kwestie van deze string aanpassen om hier iets neer te zetten.", textColor, 1000);
	helpTextTexture = SurfaceToTexture(helpText);

	SDL_QueryTexture(helpTextTexture, NULL, NULL, &helpTextRect.w, &helpTextRect.h);
	helpTextRect.x = 15;
	helpTextRect.y = 250;
	pos[5] = helpTextRect;
#pragma endregion helptext
#pragma region backToMain
	SDL_Surface* backToMain = TTF_RenderText_Blended(textFont, "Back", textColor);
	backToMainTexture = SurfaceToTexture(backToMain);

	SDL_QueryTexture(backToMainTexture, NULL, NULL, &backToMainRect.w, &backToMainRect.h);
	backToMainRect.x = 5;
	backToMainRect.y = 5;
	pos[6] = backToMainRect;
#pragma endregion helptext
#pragma region creditText
	SDL_Surface* creditText = TTF_RenderText_Blended_Wrapped(textFont, "In dit stukje tekst bedanken wij alle spelers voor het spelen van ons spel. De makers van deze game zijn:\nThomas de Brouwer\nJeroenGuelen\nMark-Jan de Jong\nRoel van Atteveld\nDaniël Eijkelenburg", textColor, 1000);
	creditTextTexture = SurfaceToTexture(creditText);

	SDL_QueryTexture(creditTextTexture, NULL, NULL, &creditTextRect.w, &creditTextRect.h);
	creditTextRect.x = 15;
	creditTextRect.y = 250;
	pos[7] = creditTextRect;
#pragma endregion creditText
#pragma region creditTitel
	SDL_Surface* creditTitle = TTF_RenderText_Blended(titleFont, "Credits", textColor);
	creditTitleTexture = SurfaceToTexture(creditTitle);

	SDL_QueryTexture(creditTitleTexture, NULL, NULL, &creditTitleRect.w, &creditTitleRect.h);
	creditTitleRect.x = 375;
	creditTitleRect.y = 5;
	pos[8] = creditTitleRect;
#pragma endregion creditTitle


}
// Convert an SDL_Surface to SDL_Texture. We've done this before, so I'll keep it short
SDL_Texture* SurfaceToTexture(SDL_Surface* surf)
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface(renderer, surf);

	SDL_FreeSurface(surf);

	return text;
}
bool InitEverything()
{
	if (!InitSDL())
		return false;

	if (!CreateWindow())
		return false;

	if (!CreateRenderer())
		return false;

	SetupRenderer();

	if (!SetupTTF("28 Days Later.ttf", "armalite_rifle.ttf"))
		return false;

	CreateTextTextures();

	return true;
}
bool InitSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}
bool CreateWindow()
{
	window = SDL_CreateWindow("Jark Hunt", windowRect.x, windowRect.y, windowRect.w, windowRect.h, 0);

	if (window == nullptr)
	{
		std::cout << "Failed to create window : " << SDL_GetError();
		return false;
	}

	return true;
}
bool CreateRenderer()
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr)
	{
		std::cout << "Failed to create renderer : " << SDL_GetError();
		return false;
	}

	return true;
}
void SetupRenderer()
{
	// Set size of renderer to the same as window
	SDL_RenderSetLogicalSize(renderer, windowRect.w, windowRect.h);

	// Set color of renderer to red
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
}


MainMenu::~MainMenu()
{
}
*/