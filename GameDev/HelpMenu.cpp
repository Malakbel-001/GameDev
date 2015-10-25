#include "HelpMenu.h"

// Setup
bool InitEverything2();
bool InitSDL2();
bool CreateWindow2();
bool CreateRenderer2();
void SetupRenderer2();
void HandleInput2();

// Our new function for setting uo SDL_TTF
bool SetupTTF2(const std::string &fontName);
SDL_Texture* SurfaceToTexture2(SDL_Surface* surf);
void CreateTextTextures2();

// Update ( happens every frame )
void Render2();
void RunGame2();

// Stuff for text rendering
TTF_Font* titleFont2;
TTF_Font* textFont2;
SDL_Color textColor2 = { 255, 255, 255, 255 }; // white
SDL_Color backgroundColor2 = { 0, 0, 0, 255 }; // black

SDL_Texture* playTexture2;
SDL_Texture* helpTexture2;
SDL_Texture* quitTexture2;
SDL_Texture* titleTexture2;

//amount of menu items (specific for each menu)
const int renderItems = 4;
SDL_Rect pos2[renderItems];

SDL_Rect solidRect2;
SDL_Rect blendedRect2;
SDL_Rect shadedRect2;
SDL_Rect titleRect2;

SDL_Rect windowRect2 = { 8, 30, 1200, 700 };
SDL_Window* window2;
SDL_Renderer* renderer2;

bool quit2 = false;

HelpMenu::HelpMenu()
{
	if (!InitEverything2()){
		std::cout << "-1";
	}
	RunGame2();

	// Clean up font
	TTF_CloseFont(titleFont2);
	TTF_CloseFont(textFont2);
}

void RunGame2()
{
	while (!quit2){

		HandleInput2();

		Render2();
	}
	/*Render();
	std::cout << "Press any key to exit\n";
	std::cin.ignore();
	*/



	//exit main menu
	SDL_DestroyWindow(window2);
}

void HandleInput2(){
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type){
		case SDL_QUIT:
			quit2 = true;
			break;
		case SDL_MOUSEBUTTONDOWN:
			int x = event.button.x;
			int y = event.button.y;
			for (int i = 0; i < renderItems; i++){
				if (x >= pos2[i].x && x <= pos2[i].x + pos2[i].w && y >= pos2[i].y && y <= pos2[i].y + pos2[i].h){
					switch (i){
						//item 1, play
					case 0:
						quit2 = true;
						break;
						//item 2, help
					case 1:
						break;
						//item 3, quit
					case 2:
						SDL_DestroyWindow(window2);
						break;
					}
				}
			}
			break;
			
		}
	}
}

void Render2()
{
	// Clear the window and make it all red
	SDL_RenderClear(renderer2);

	// Render our text objects ( like normal )
	SDL_RenderCopy(renderer2, playTexture2, nullptr, &solidRect2);
	SDL_RenderCopy(renderer2, helpTexture2, nullptr, &blendedRect2);
	SDL_RenderCopy(renderer2, quitTexture2, nullptr, &shadedRect2);
	SDL_RenderCopy(renderer2, titleTexture2, nullptr, &titleRect2);

	// Render the changes above
	SDL_RenderPresent(renderer2);
}
// Initialization ++
// ==================================================================
bool SetupTTF2(const std::string &fontName, const std::string &fontName2)
{
	// SDL2_TTF needs to be initialized just like SDL2
	if (TTF_Init() == -1)
	{
		std::cout << " Failed to initialize TTF : " << TTF_GetError() << std::endl;
		return false;
	}

	// Load our fonts, with a huge size
	titleFont2 = TTF_OpenFont(fontName2.c_str(), 90);
	textFont2 = TTF_OpenFont(fontName.c_str(), 40);

	// Error check
	if (titleFont2 == nullptr)
	{
		std::cout << " Failed to load font : " << TTF_GetError() << std::endl;
		return false;
	}

	if (textFont2 == nullptr)
	{
		std::cout << " Failed to load font : " << TTF_GetError() << std::endl;
		return false;
	}

	return true;
}
void CreateTextTextures2()
{
	SDL_Surface* play2 = TTF_RenderText_Blended_Wrapped(textFont2, "Dit is een help menu. Hierin wordt beschreven hoe het spel werkt en wat het doel is en eventuele extra informatie die nu nog niet bekend is maar het is gewoon een kwestie van deze string aanpassen om hier iets neer te zetten.", textColor2, 1000);
	playTexture2 = SurfaceToTexture2(play2);

	SDL_QueryTexture(playTexture2, NULL, NULL, &solidRect2.w, &solidRect2.h);
	solidRect2.x = 15;
	solidRect2.y = 250;
	pos2[0] = solidRect2;

	SDL_Surface* help2 = TTF_RenderText_Blended(textFont2, "", textColor2);
	helpTexture2 = SurfaceToTexture2(help2);

	SDL_QueryTexture(helpTexture2, NULL, NULL, &blendedRect2.w, &blendedRect2.h);
	blendedRect2.x = 15;
	blendedRect2.y = solidRect2.y + solidRect2.h + 20;
	pos2[1] = blendedRect2;

	SDL_Surface* quit2 = TTF_RenderText_Blended(textFont2, "Back", textColor2);
	quitTexture2 = SurfaceToTexture2(quit2);

	SDL_QueryTexture(quitTexture2, NULL, NULL, &shadedRect2.w, &shadedRect2.h);
	shadedRect2.x = 15;
	shadedRect2.y = blendedRect2.y + blendedRect2.h + 20;
	pos2[2] = shadedRect2;

	SDL_Surface* title2 = TTF_RenderText_Blended(titleFont2, "Help Menu", textColor2);
	titleTexture2 = SurfaceToTexture2(title2);

	SDL_QueryTexture(titleTexture2, NULL, NULL, &titleRect2.w, &titleRect2.h);
	titleRect2.x = 375;
	titleRect2.y = 5;
	pos2[3] = titleRect2;
}
// Convert an SDL_Surface to SDL_Texture. We've done this before, so I'll keep it short
SDL_Texture* SurfaceToTexture2(SDL_Surface* surf)
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface(renderer2, surf);

	SDL_FreeSurface(surf);

	return text;
}
bool InitEverything2()
{
	if (!InitSDL2())
		return false;

	if (!CreateWindow2())
		return false;

	if (!CreateRenderer2())
		return false;

	SetupRenderer2();

	if (!SetupTTF2("armalite_rifle.ttf", "28 Days Later.ttf"))
		return false;

	CreateTextTextures2();

	return true;
}
bool InitSDL2()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}
bool CreateWindow2()
{
	window2 = SDL_CreateWindow("Server", windowRect2.x, windowRect2.y, windowRect2.w, windowRect2.h, 0);

	if (window2 == nullptr)
	{
		std::cout << "Failed to create window : " << SDL_GetError();
		return false;
	}

	return true;
}
bool CreateRenderer2()
{
	renderer2 = SDL_CreateRenderer(window2, -1, SDL_RENDERER_ACCELERATED);

	if (renderer2 == nullptr)
	{
		std::cout << "Failed to create renderer : " << SDL_GetError();
		return false;
	}

	return true;
}
void SetupRenderer2()
{
	// Set size of renderer to the same as window
	SDL_RenderSetLogicalSize(renderer2, windowRect2.w, windowRect2.h);

	// Set color of renderer to red
	SDL_SetRenderDrawColor(renderer2, 255, 0, 0, 255);
}


HelpMenu::~HelpMenu()
{
}
