#include "MenuState.h"

const int renderItems = 10;
SDL_Rect pos[renderItems];

SDL_Color textColor = { 255, 255, 255, 255 }; // white

void MenuState::Init(GameStateManager *gsm){
	this->gsm = gsm;
	if (!InitEverything()){
		std::cout << "-1";
	}
	SoundBank::GetInstance()->PlayBGM(SoundBgmType::TESTBGM1, 64);
	menuState = mainMenu;
	cout << "MenuState \n";
	Update(0);
}

MenuState::MenuState()
{
}

void MenuState::loadMainMenu(){
	SDL_RenderCopy(renderer, playTexture, nullptr, &solidRect);
	SDL_RenderCopy(renderer, helpTexture, nullptr, &blendedRect);
	SDL_RenderCopy(renderer, quitTexture, nullptr, &shadedRect);
	SDL_RenderCopy(renderer, creditTexture, nullptr, &creditRect);
	SDL_RenderCopy(renderer, mainTitleTexture, nullptr, &mainTitleRect);
}

void MenuState::loadHelpMenu(){
	SDL_RenderCopy(renderer, helpTextTexture, nullptr, &helpTextRect);
	SDL_RenderCopy(renderer, helpTitleTexture, nullptr, &helpTitleRect);
	SDL_RenderCopy(renderer, backToMainTexture, nullptr, &backToMainRect);
}

void MenuState::LoadCreditMenu(){
	SDL_RenderCopy(renderer, creditTextTexture, nullptr, &creditTextRect);
	SDL_RenderCopy(renderer, creditTitleTexture, nullptr, &creditTitleRect);
	SDL_RenderCopy(renderer, backToMainTexture, nullptr, &backToMainRect);
}

// Initialization ++
// ==================================================================
bool MenuState::SetupTTF(const std::string &fontName, const std::string &fontName2)
{
	// SDL2_TTF needs to be initialized just like SDL2
	if (TTF_Init() == -1)
	{
		std::cout << " Failed to initialize TTF : " << TTF_GetError() << std::endl;
		return false;
	}

	// Load our fonts, with a huge size
	titleFont = TTF_OpenFont(fontName.c_str(), 90);
	textFont = TTF_OpenFont(fontName2.c_str(), 23);

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
void MenuState::CreateTextTextures()
{
#pragma region play
	SDL_Surface* play = TTF_RenderText_Blended(textFont, "Play", textColor);
	playTexture = SurfaceToTexture(play);

	SDL_QueryTexture(playTexture, NULL, NULL, &solidRect.w, &solidRect.h);
	solidRect.x = 15;
	solidRect.y = 150;
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
	mainTitleRect.x = 150;
	mainTitleRect.y = 5;
	pos[3] = mainTitleRect;
#pragma endregion maintitle
#pragma region helptitle
	SDL_Surface* helpTitle = TTF_RenderText_Blended(titleFont, "Help", textColor);
	helpTitleTexture = SurfaceToTexture(helpTitle);

	SDL_QueryTexture(helpTitleTexture, NULL, NULL, &helpTitleRect.w, &helpTitleRect.h);
	helpTitleRect.x = 200;
	helpTitleRect.y = 5;
	pos[4] = helpTitleRect;
#pragma endregion helptitle
#pragma region helptext
	SDL_Surface* helpText = TTF_RenderText_Blended_Wrapped(textFont, "Dit is een help menu. Hierin wordt beschreven hoe het spel werkt en wat het doel is en eventuele extra informatie die nu nog niet bekend is maar het is gewoon een kwestie van deze string aanpassen om hier iets neer te zetten.", textColor, 600);
	helpTextTexture = SurfaceToTexture(helpText);

	SDL_QueryTexture(helpTextTexture, NULL, NULL, &helpTextRect.w, &helpTextRect.h);
	helpTextRect.x = 15;
	helpTextRect.y = 150;
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
	SDL_Surface* creditText = TTF_RenderText_Blended_Wrapped(textFont, "In dit stukje tekst bedanken wij alle spelers voor het spelen van ons spel. De makers van deze game zijn:\nThomas de Brouwer\nJeroenGuelen\nMark-Jan de Jong\nRoel van Atteveld\nDaniE Eijkelenburg", textColor, 600);
	creditTextTexture = SurfaceToTexture(creditText);

	SDL_QueryTexture(creditTextTexture, NULL, NULL, &creditTextRect.w, &creditTextRect.h);
	creditTextRect.x = 15;
	creditTextRect.y = 150;
	pos[7] = creditTextRect;
#pragma endregion creditText
#pragma region creditTitel
	SDL_Surface* creditTitle = TTF_RenderText_Blended(titleFont, "Credits", textColor);
	creditTitleTexture = SurfaceToTexture(creditTitle);

	SDL_QueryTexture(creditTitleTexture, NULL, NULL, &creditTitleRect.w, &creditTitleRect.h);
	creditTitleRect.x = 150;
	creditTitleRect.y = 5;
	pos[8] = creditTitleRect;
#pragma endregion creditTitle


}
// Convert an SDL_Surface to SDL_Texture. We've done this before, so I'll keep it short
SDL_Texture* MenuState::SurfaceToTexture(SDL_Surface* surf)
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface(renderer, surf);

	SDL_FreeSurface(surf);

	return text;
}
bool MenuState::InitEverything()
{
	if (!InitSDL())
		return false;

	if (!CreateRenderer())
		return false;

	SetupRenderer();

	if (!SetupTTF("28 Days Later.ttf", "armalite_rifle.ttf"))
		return false;

	CreateTextTextures();

	return true;
}
bool MenuState::InitSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}
bool MenuState::CreateRenderer()
{
	//renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	renderer = gsm->GetBehaviour()->GetRenderer();
	if (renderer == nullptr)
	{
		std::cout << "Failed to create renderer : " << SDL_GetError();
		return false;
	}

	return true;
}
void MenuState::SetupRenderer()
{
	// Set size of renderer to the same as window
	//SDL_RenderSetLogicalSize(renderer, windowRect.w, windowRect.h);

	background = LTexture();
	background.loadFromFile(gsm->GetBehaviour()->GetRenderer(), "menu.jpg");
	backgroundRect.h = background.getHeight();
	backgroundRect.w = background.getWidth();
	backgroundRect.x = 0;
	backgroundRect.y = 0;

	// Set color of renderer to red
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
}


MenuState::~MenuState()
{
}

void MenuState::Cleanup(){
	// Clean up font
	TTF_CloseFont(titleFont);
	TTF_CloseFont(textFont);
}

void MenuState::Pause(){

}
void MenuState::Resume(){

}

void MenuState::HandleMouseEvents(SDL_Event mainEvent)
{
	switch (mainEvent.type)
	{
	case SDL_QUIT:
		quit = true;
		break;
	case SDL_MOUSEBUTTONDOWN:
		int x = mainEvent.button.x;
		int y = mainEvent.button.y;
		for (int i = 0; i < renderItems; i++)
		{
			if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h){
				switch (i){
					//item 1, mainmenu play
				case 0:
					if (menuState == mainMenu){
						SoundBank::GetInstance()->Play(SoundEffectType::CORRECT, 64);
						SoundBank::GetInstance()->StopMusic();
						this->gsm->ChangeGameState(new PlayState());
						quit = true;
					}
					break;
					//item 2, mainmenu help
				case 1:
					if (menuState == mainMenu){
						SoundBank::GetInstance()->Play(SoundEffectType::CORRECT, 64);
						menuState = helpMenu;
					}
					break;
					//item 3,mainmenu quit
				case 2:
					if (menuState == mainMenu){
						exit(0);
					}
					break;
					//item 6, backtomain
				case 6:
					if (menuState != mainMenu)
					{
						SoundBank::GetInstance()->Play(SoundEffectType::CORRECT, 64);
						menuState = mainMenu;
					}
					break;
					//item 9, mainmenu credit
				case 9:
					if (menuState == mainMenu){
						SoundBank::GetInstance()->Play(SoundEffectType::CORRECT, 64);
						menuState = creditMenu;
					}
					break;
				}
			}
		}
		break;
	}
}

void MenuState::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events)
{
	//std::cout << "Key events not implemented yet";
}

void MenuState::Update(float dt){
	/*while (!quit){

		HandleEvents();

		Draw();
	}*/
}
void MenuState::Draw(){
	SDL_RenderClear(renderer);

	background.render(renderer, 0, 0, &backgroundRect);

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