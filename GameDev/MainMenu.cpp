#include "MainMenu.h"

// Setup
bool InitEverything();
bool InitSDL();
bool CreateWindow();
bool CreateRenderer();
void SetupRenderer();
void HandleInput();

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

SDL_Texture* playTexture;
SDL_Texture* helpTexture;
SDL_Texture* quitTexture;
SDL_Texture* titleTexture;

//amount of menu items (specific for each menu)
const int renderItems = 4;
SDL_Rect pos[renderItems];

SDL_Rect solidRect;
SDL_Rect blendedRect;
SDL_Rect shadedRect;
SDL_Rect titleRect;

SDL_Rect windowRect = { 8, 30, 1200, 700 };
SDL_Window* window;
SDL_Renderer* renderer;

bool quit = false;

MainMenu::MainMenu()
{
	if (!InitEverything()){
		std::cout << "-1";
	}
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
	/*Render();
	std::cout << "Press any key to exit\n";
	std::cin.ignore();
	*/



	//exit main menu
	SDL_DestroyWindow(window);
}

void HandleInput(){
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type){
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_MOUSEBUTTONDOWN:
			int x = event.button.x;
			int y = event.button.y;
			for (int i = 0; i < renderItems; i++){
				if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h){
					switch (i){
						//item 1, play
					case 0:
						std::cout << "play";
						quit = true;
						break;
						//item 2, help
					case 1:
						std::cout << "help";
						break;
						//item 3, quit
					case 2:
						exit(0);
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
	// Clear the window and make it all red
	SDL_RenderClear(renderer);

	// Render our text objects ( like normal )
	SDL_RenderCopy(renderer, playTexture, nullptr, &solidRect);
	SDL_RenderCopy(renderer, helpTexture, nullptr, &blendedRect);
	SDL_RenderCopy(renderer, quitTexture, nullptr, &shadedRect);
	SDL_RenderCopy(renderer, titleTexture, nullptr, &titleRect);

	// Render the changes above
	SDL_RenderPresent(renderer);
}
// Initialization ++
// ==================================================================
bool SetupTTF(const std::string &fontName)
{
	// SDL2_TTF needs to be initialized just like SDL2
	if (TTF_Init() == -1)
	{
		std::cout << " Failed to initialize TTF : " << TTF_GetError() << std::endl;
		return false;
	}

	// Load our fonts, with a huge size
	titleFont = TTF_OpenFont(fontName.c_str(), 90);
	textFont = TTF_OpenFont(fontName.c_str(), 40);

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
	SDL_Surface* play = TTF_RenderText_Blended(textFont, "Play", textColor);
	playTexture = SurfaceToTexture(play);

	SDL_QueryTexture(playTexture, NULL, NULL, &solidRect.w, &solidRect.h);
	solidRect.x = 15;
	solidRect.y = 250;
	pos[0] = solidRect;

	SDL_Surface* help = TTF_RenderText_Blended(textFont, "Help", textColor);
	helpTexture = SurfaceToTexture(help);

	SDL_QueryTexture(helpTexture, NULL, NULL, &blendedRect.w, &blendedRect.h);
	blendedRect.x = 15;
	blendedRect.y = solidRect.y + solidRect.h + 20;
	pos[1] = blendedRect;

	SDL_Surface* quit = TTF_RenderText_Blended(textFont, "Quit", textColor);
	quitTexture = SurfaceToTexture(quit);

	SDL_QueryTexture(quitTexture, NULL, NULL, &shadedRect.w, &shadedRect.h);
	shadedRect.x = 15;
	shadedRect.y = blendedRect.y + blendedRect.h + 20;
	pos[2] = shadedRect;

	SDL_Surface* title = TTF_RenderText_Blended(titleFont, "Jark Hunt", textColor);
	titleTexture = SurfaceToTexture(title);

	SDL_QueryTexture(titleTexture, NULL, NULL, &titleRect.w, &titleRect.h);
	titleRect.x = 375;
	titleRect.y = 5;
	pos[3] = titleRect;
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

	if (!SetupTTF("28 Days Later.ttf"))
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
	window = SDL_CreateWindow("Server", windowRect.x, windowRect.y, windowRect.w, windowRect.h, 0);

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
