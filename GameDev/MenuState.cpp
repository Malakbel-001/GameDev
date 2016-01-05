#include "MenuState.h"
#include "MainMenu.h"
#include "HelpMenu.h"
#include "CreditMenu.h"
#include "OptionMenu.h"
#include "PlayMenu.h"
#include "HighscoreMenu.h"
const int renderItems = 20;
SDL_Rect pos[renderItems];

SDL_Color textColor = { 255, 255, 255, 255 }; // white
SDL_Color hoverTextColor = { 255, 0, 0, 255 }; // red

void MenuState::Init(GameStateManager *gsm){

	this->gsm = gsm;
	if (!InitEverything()){
		std::cout << "-1";
	}
	SoundBank::GetInstance()->PlayBGM(SoundBgmType::REDALERT2);
	//menuState = mainMenu;
	cout << "MenuState \n";
	
	mainMenu = new MainMenu(this, renderer, textFont, titleFont);
	helpMenu = new HelpMenu(this, renderer, textFont, titleFont);
	creditMenu = new CreditMenu(this, renderer, textFont, titleFont);
	optionMenu = new OptionMenu(this, renderer, textFont, titleFont);
	playMenu = new PlayMenu(this, renderer, textFont, titleFont);
	highscoreMenu = new HighscoreMenu(this, renderer, textFont, titleFont);
	currentMenu = mainMenu;
}

MenuState::MenuState()
{
	pos.resize(renderItems);
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
	textFont = TTF_OpenFont(fontName2.c_str(), 30);

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

bool MenuState::InitEverything()
{
	if (!InitSDL())
		return false;

	if (!CreateRenderer())
		return false;

	SetupRenderer();

	if (!SetupTTF("28 Days Later.ttf", "armalite_rifle.ttf"))
		return false;

	//CreateTextTextures();

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
}


MenuState::~MenuState()
{
	delete mainMenu;
	delete helpMenu;
	delete creditMenu;
	delete optionMenu;
	delete playMenu;
	delete highscoreMenu;
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
	currentMenu->HandleMouseEvents(mainEvent);
}

void MenuState::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events)
{
	//std::cout << "Key events not implemented yet";
}

void MenuState::HandleTextInputEvents(SDL_Event event){

}

void MenuState::Update(float dt, float manipulatorSpeed){
	
}

void MenuState::updateMenu(MenuEnum menu){
	switch (menu)
	{
	case MenuEnum::Previous:
		currentMenu = PreviousMenu;
		PreviousMenu = nullptr;
	case MenuEnum::Main:
		currentMenu = mainMenu;
		PreviousMenu = nullptr;
		break;
	case MenuEnum::Help:
		currentMenu = helpMenu;
		PreviousMenu = mainMenu;
		break;
	case MenuEnum::Credits:
		currentMenu = creditMenu;
		PreviousMenu = mainMenu;
		break;
	case MenuEnum::Options:
		currentMenu = optionMenu;
		PreviousMenu = mainMenu;
		break;
	case MenuEnum::Play:
		playMenu->LoadLevels();
		currentMenu = playMenu;
		PreviousMenu = mainMenu;
		//gsm->CreateGameState(GameStateType::LoadState);
		break;
	case MenuEnum::Highscore:
		highscoreMenu->LoadScores();
		highscoreMenu->UpdateScore();
		currentMenu = highscoreMenu;
		PreviousMenu = mainMenu;
		break;
	default:
		break;
	}
}
void MenuState::Draw(float dt, float manipulatorSpeed){
	SDL_RenderClear(renderer);
	background.render(renderer, 0, 0,0, &backgroundRect);
	currentMenu->Draw();
	SDL_RenderPresent(renderer);
}