#include "PauseState.h"
#include "PauseMenu.h"
#include "HelpMenu.h"
#include "CreditMenu.h"
#include "OptionMenu.h"


void PauseState::Init(GameStateManager *gsm){
	this->gsm = gsm;
	if (!InitEverything()){
		std::cout << "-1";
	}
	SoundBank::GetInstance()->PlayBGM(SoundBgmType::REDALERT2);
	cout << "PauseState \n";

	pauseMenu = new PauseMenu(this, renderer, textFont, titleFont);
	helpMenu = new HelpMenu(this, renderer, textFont, titleFont);
	creditMenu = new CreditMenu(this, renderer, textFont, titleFont);
	optionMenu = new OptionMenu(this, renderer, textFont, titleFont, parallaxBackground);
	currentMenu = pauseMenu;
}

PauseState::PauseState()
{
}
// Initialization ++
// ==================================================================
bool PauseState::SetupTTF(const std::string &fontName, const std::string &fontName2)
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

bool PauseState::InitEverything()
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
bool PauseState::InitSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}
bool PauseState::CreateRenderer()
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
void PauseState::SetupRenderer()
{
	// Set size of renderer to the same as window
	//SDL_RenderSetLogicalSize(renderer, windowRect.w, windowRect.h);

	parallaxBackground = new ParallaxBackground(gsm->GetBehaviour()->GetRenderer(), 1);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-back-trees.png", 0, 0.9f, 255);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-lights.png", 0, 0.7f, 120); //cool transparency feature
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-middle-trees.png", 0, 1.2f, 255);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-front-trees.png", 0, 1.5f, 255);
}


PauseState::~PauseState()
{
	delete pauseMenu;
	
	delete helpMenu;
	delete creditMenu;
	delete optionMenu;
}

void PauseState::Cleanup(){
	// Clean up font
	TTF_CloseFont(titleFont);
	TTF_CloseFont(textFont);
}

void PauseState::Pause(){

}
void PauseState::Resume(){

}

void PauseState::HandleMouseEvents(SDL_Event mainEvent)
{
	currentMenu->HandleMouseEvents(mainEvent);

}

void PauseState::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events)
{
	//std::cout << "Key events not implemented yet";
}

void PauseState::Update(float dt, float manipulatorSpeed){

}

void PauseState::HandleTextInputEvents(SDL_Event event){

}



void PauseState::updateMenu(MenuEnum menu){
	switch (menu)
	{
	case MenuEnum::Resume:
		gsm->PopState();
		break;
	case MenuEnum::Previous:
		currentMenu = PreviousMenu;
		PreviousMenu = nullptr;
		break;
	case MenuEnum::Main:
	{
		PreviousMenu = nullptr;
		gsm->PopState();
		gsm->PopState();
		MenuState* tempState = (MenuState*)gsm->GetCurrentState();
		tempState->updateMenu(MenuEnum::Previous);
		break;
	}
	case MenuEnum::Help:
		currentMenu = helpMenu;
		PreviousMenu = pauseMenu;
		break;
	case MenuEnum::Credits:
		currentMenu = creditMenu;
		PreviousMenu = pauseMenu;
		break;
	case MenuEnum::Options:
		currentMenu = optionMenu;
		PreviousMenu = pauseMenu;
		break;
	case MenuEnum::Play:
		gsm->CreatePlayState(0);
		break;
	default:
		break;
	}
}
void PauseState::Draw(float dt, float manipulatorSpeed){
	SDL_RenderClear(renderer);
	parallaxBackground->Draw();
	currentMenu->Draw();
	SDL_RenderPresent(renderer);
}