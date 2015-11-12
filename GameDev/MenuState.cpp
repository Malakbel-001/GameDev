#include "MenuState.h"

const int renderItems = 16;
SDL_Rect pos[renderItems];

SDL_Color textColor = { 255, 255, 255, 255 }; // white

void MenuState::Init(GameStateManager *gsm){
	this->gsm = gsm;
	if (!InitEverything()){
		std::cout << "-1";
	}
	SoundBank::GetInstance()->PlayBGM(SoundBgmType::TESTBGM1);
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
	SDL_RenderCopy(renderer, optionsTexture, nullptr, &optionsRect); //NEW
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

void MenuState::LoadOptionsMenu() {
	SDL_RenderCopy(renderer, sfxOnTexture, nullptr, &sfxOnRect);
	SDL_RenderCopy(renderer, musicOnTexture, nullptr, &musicOnRect);
	SDL_RenderCopy(renderer, backToMainTexture, nullptr, &backToMainRect);
	//SDL_RenderCopy(renderer, sfxOffTexture, nullptr, &sfxOffRect);
	//SDL_RenderCopy(renderer, musicOffTexture, nullptr, &musicOffRect);
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
	solidRect.y = 225;
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
#pragma region options
	SDL_Surface* options = TTF_RenderText_Blended(textFont, "Options", textColor);
	optionsTexture = SurfaceToTexture(options);

	SDL_QueryTexture(optionsTexture, NULL, NULL, &optionsRect.w, &optionsRect.h);
	optionsRect.x = 15;
	optionsRect.y = creditRect.y + creditRect.h + 20;
	pos[10] = optionsRect;
#pragma endregion options
#pragma region quit
	SDL_Surface* quit = TTF_RenderText_Blended(textFont, "Quit", textColor);
	quitTexture = SurfaceToTexture(quit);

	SDL_QueryTexture(quitTexture, NULL, NULL, &shadedRect.w, &shadedRect.h);
	shadedRect.x = 15;
	shadedRect.y = optionsRect.y + optionsRect.h + 20;
	pos[2] = shadedRect;
#pragma endregion quit
#pragma region maintitle
	SDL_Surface* mainTitle = TTF_RenderText_Blended(titleFont, "Jark Hunt", textColor);
	mainTitleTexture = SurfaceToTexture(mainTitle);

	SDL_QueryTexture(mainTitleTexture, NULL, NULL, &mainTitleRect.w, &mainTitleRect.h);
	mainTitleRect.x = 540 - (mainTitleRect.w / 2);
	mainTitleRect.y = 5;
	pos[3] = mainTitleRect;
#pragma endregion maintitle
#pragma region helptitle
	SDL_Surface* helpTitle = TTF_RenderText_Blended(titleFont, "Help", textColor);
	helpTitleTexture = SurfaceToTexture(helpTitle);

	SDL_QueryTexture(helpTitleTexture, NULL, NULL, &helpTitleRect.w, &helpTitleRect.h);
	helpTitleRect.x = 540 - (helpTitleRect.w / 2);
	helpTitleRect.y = 5;
	pos[4] = helpTitleRect;
#pragma endregion helptitle
#pragma region helptext
	SDL_Surface* helpText = TTF_RenderText_Blended_Wrapped(textFont, "Het Spel bestuur je doormiddel van het toetsenboard. Je gebruik de volgende knoppen om de speler te besturen:\n-W = Springen/Klimmen.\n-A = Naar links lopen.\n-S = Naar beneden klimmen.\n-D = Naar rechts lopen.\n\nNog een tip, probeer vooral op het gras te blijven, anders is de kans op overleven erg klein.", textColor, 1000);
	helpTextTexture = SurfaceToTexture(helpText);

	SDL_QueryTexture(helpTextTexture, NULL, NULL, &helpTextRect.w, &helpTextRect.h);
	helpTextRect.x = 15;
	helpTextRect.y = 225;
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
	SDL_Surface* creditText = TTF_RenderText_Blended_Wrapped(textFont, "In dit stukje tekst bedanken wij alle spelers voor het spelen van ons spel. De makers van deze game zijn:\n-Thomas de Brouwer\n-Jeroen Guelen\n-Mark-Jan de Jong\n-Roel van Atteveld\n-Daniel Eijkelenboom", textColor, 1000);
	creditTextTexture = SurfaceToTexture(creditText);

	SDL_QueryTexture(creditTextTexture, NULL, NULL, &creditTextRect.w, &creditTextRect.h);
	creditTextRect.x = 15;
	creditTextRect.y = 225;
	pos[7] = creditTextRect;
#pragma endregion creditText
#pragma region creditTitel
	SDL_Surface* creditTitle = TTF_RenderText_Blended(titleFont, "Credits", textColor);
	creditTitleTexture = SurfaceToTexture(creditTitle);

	SDL_QueryTexture(creditTitleTexture, NULL, NULL, &creditTitleRect.w, &creditTitleRect.h);
	creditTitleRect.x = 540 - (creditTitleRect.w / 2);
	creditTitleRect.y = 5;
	pos[8] = creditTitleRect;
#pragma endregion creditTitle
#pragma region optionsTitle
	SDL_Surface* optionsTitle = TTF_RenderText_Blended(titleFont, "Options", textColor);
	optionsTitleTexture = SurfaceToTexture(optionsTitle);

	SDL_QueryTexture(optionsTitleTexture, NULL, NULL, &optionsTitleRect.w, &optionsTitleRect.h);
	optionsTitleRect.x = 540 - (optionsTitleRect.w / 2);
	optionsTitleRect.y = 5;
	pos[15] = optionsTitleRect;
#pragma endregion optionsTitle
#pragma region sfxOn
	SDL_Surface* sfxOnButton = TTF_RenderText_Blended(textFont, "Sound effects - On", textColor);
	sfxOnTexture = SurfaceToTexture(sfxOnButton);

	SDL_QueryTexture(sfxOnTexture, NULL, NULL, &sfxOnRect.w, &sfxOnRect.h);
	sfxOnRect.x = 15;
	sfxOnRect.y = 225;
	pos[11] = sfxOnRect;
#pragma endregion sfxOn
#pragma region musicOn
	SDL_Surface* musicOnButton = TTF_RenderText_Blended(textFont, "Music - On", textColor);
	musicOnTexture = SurfaceToTexture(musicOnButton);

	SDL_QueryTexture(musicOnTexture, NULL, NULL, &musicOnRect.w, &musicOnRect.h);
	musicOnRect.x = 15;
	musicOnRect.y = sfxOnRect.y + sfxOnRect.h + 20;
	pos[12] = musicOnRect;
#pragma endregion musicOn
#pragma region sfxOff
	SDL_Surface* sfxOffButton = TTF_RenderText_Blended(textFont, "Sound effects - Off", textColor);
	sfxOffTexture = SurfaceToTexture(sfxOffButton);

	SDL_QueryTexture(sfxOffTexture, NULL, NULL, &sfxOffRect.w, &sfxOffRect.h);
	sfxOffRect.x = 15;
	sfxOffRect.y = 225;
	pos[13] = sfxOffRect;
#pragma endregion sfxOff
#pragma region musicOff
	SDL_Surface* musicOffButton = TTF_RenderText_Blended(textFont, "Music - Off", textColor);
	musicOffTexture = SurfaceToTexture(musicOffButton);

	SDL_QueryTexture(musicOffTexture, NULL, NULL, &musicOffRect.w, &musicOffRect.h);
	musicOffRect.x = 15;
	musicOffRect.y = sfxOnRect.y + sfxOnRect.h + 20;
	pos[14] = musicOffRect;
#pragma endregion musicOff

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
						SoundBank::GetInstance()->Play(SoundEffectType::CORRECT);
						SoundBank::GetInstance()->StopMusic();
						gsm->CreateGameState(GameStateType::PlayState);
						
						quit = true;
					}
					break;
					//item 2, mainmenu help
				case 1:
					if (menuState == mainMenu){
						SoundBank::GetInstance()->Play(SoundEffectType::CORRECT);
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
						SoundBank::GetInstance()->Play(SoundEffectType::CORRECT);
						menuState = mainMenu;
					}
					break;
					//item 9, mainmenu credit
				case 9:
					if (menuState == mainMenu){
						SoundBank::GetInstance()->Play(SoundEffectType::CORRECT);
						menuState = creditMenu;
					}
					break;
					//item 10, mainmenu options
				case 10:
					if (menuState == mainMenu) {
						SoundBank::GetInstance()->Play(SoundEffectType::CORRECT);
						menuState = optionsMenu;
					}
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
	case optionsMenu:
		LoadOptionsMenu();
		break;
	}
	SDL_RenderPresent(renderer);
}