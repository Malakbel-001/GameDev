#include "PauseState.h"

const int renderItems = 18;


void PauseState::Init(GameStateManager *gsm){
	this->gsm = gsm;
	if (!InitEverything()){
		std::cout << "-1";
	}
	SoundBank::GetInstance()->PlayBGM(SoundBgmType::TESTBGM1);
	menuState = pauseMenu;
	cout << "PauseState \n";
	Update(0);
}

PauseState::PauseState()
{
	textColor = { 255, 255, 255, 255 }; // white	
	pos.resize(renderItems);
}

void PauseState::loadPauseMenu(){
	SDL_RenderCopy(renderer, resumeTexture, nullptr, &solidRect);
	SDL_RenderCopy(renderer, helpTexture, nullptr, &blendedRect);
	SDL_RenderCopy(renderer, optionsTexture, nullptr, &optionsRect); //NEW
	SDL_RenderCopy(renderer, quitTexture, nullptr, &shadedRect);
	SDL_RenderCopy(renderer, pauseTitleTexture, nullptr, &pauseTitleRect);
}

void PauseState::loadHelpMenu(){
	SDL_RenderCopy(renderer, helpTextTexture, nullptr, &helpTextRect);
	SDL_RenderCopy(renderer, helpTitleTexture, nullptr, &helpTitleRect);
	SDL_RenderCopy(renderer, backToPauseTexture, nullptr, &backToPauseRect);
}

void PauseState::LoadOptionsMenu() {
	SDL_RenderCopy(renderer, optionsTitleTexture, nullptr, &optionsTitleRect);
	if (SoundBank::GetInstance()->IsEnabledMusic()) {
		SDL_RenderCopy(renderer, musicOnTexture, nullptr, &musicOnRect);
	}
	else {
		SDL_RenderCopy(renderer, musicOffTexture, nullptr, &musicOffRect);
	}
	if (SoundBank::GetInstance()->IsEnabledSFX()) {
		SDL_RenderCopy(renderer, sfxOnTexture, nullptr, &sfxOnRect);
	}
	else {
		SDL_RenderCopy(renderer, sfxOffTexture, nullptr, &sfxOffRect);
	}
	SDL_RenderCopy(renderer, backToPauseTexture, nullptr, &backToPauseRect);
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
void PauseState::CreateTextTextures()
{
#pragma region resume
	SDL_Surface* play = TTF_RenderText_Blended(textFont, "Resume", textColor);
	resumeTexture = SurfaceToTexture(play);

	SDL_QueryTexture(resumeTexture, NULL, NULL, &solidRect.w, &solidRect.h);
	solidRect.x = 15;
	solidRect.y = 225;
	pos[0] = solidRect;
#pragma endregion resume
#pragma region help
	SDL_Surface* help = TTF_RenderText_Blended(textFont, "Help", textColor);
	helpTexture = SurfaceToTexture(help);

	SDL_QueryTexture(helpTexture, NULL, NULL, &blendedRect.w, &blendedRect.h);
	blendedRect.x = 15;
	blendedRect.y = solidRect.y + solidRect.h + 20;
	pos[1] = blendedRect;
#pragma endregion help
#pragma region options
	SDL_Surface* options = TTF_RenderText_Blended(textFont, "Options", textColor);
	optionsTexture = SurfaceToTexture(options);

	SDL_QueryTexture(optionsTexture, NULL, NULL, &optionsRect.w, &optionsRect.h);
	optionsRect.x = 15;
	optionsRect.y = blendedRect.y + blendedRect.h + 20;
	pos[10] = optionsRect;
#pragma endregion options
#pragma region quit
	SDL_Surface* quit = TTF_RenderText_Blended(textFont, "Back To main-menu", textColor);
	quitTexture = SurfaceToTexture(quit);

	SDL_QueryTexture(quitTexture, NULL, NULL, &shadedRect.w, &shadedRect.h);
	shadedRect.x = 15;
	shadedRect.y = optionsRect.y + optionsRect.h + 20;
	pos[2] = shadedRect;
#pragma endregion quit
#pragma region pausetitle
	SDL_Surface* mainTitle = TTF_RenderText_Blended(titleFont, "Pause Menu", textColor);
	pauseTitleTexture = SurfaceToTexture(mainTitle);

	SDL_QueryTexture(pauseTitleTexture, NULL, NULL, &pauseTitleRect.w, &pauseTitleRect.h);
	pauseTitleRect.x = 540 - (pauseTitleRect.w / 2);
	pauseTitleRect.y = 5;
	pos[3] = pauseTitleRect;
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
	SDL_Surface* backToPause = TTF_RenderText_Blended(textFont, "Back", textColor);
	backToPauseTexture = SurfaceToTexture(backToPause);

	SDL_QueryTexture(backToPauseTexture, NULL, NULL, &backToPauseRect.w, &backToPauseRect.h);
	backToPauseRect.x = 5;
	backToPauseRect.y = 5;
	pos[6] = backToPauseRect;
#pragma endregion helptext
#pragma region optionstitle
	SDL_Surface* optionsTitle = TTF_RenderText_Blended(titleFont, "Options", textColor);
	optionsTitleTexture = SurfaceToTexture(optionsTitle);

	SDL_QueryTexture(optionsTitleTexture, NULL, NULL, &optionsTitleRect.w, &optionsTitleRect.h);
	optionsTitleRect.x = 540 - (optionsTitleRect.w / 2);
	optionsTitleRect.y = 5;
	pos[15] = optionsTitleRect;
#pragma endregion optionstitle
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
	//#pragma region fullscreenOn
	//	SDL_Surface* fullScreenOnButton = TTF_RenderText_Blended(textFont, "Fullscreen - On", textColor);
	//	fullScreenOnTexture = SurfaceToTexture(fullScreenOnButton);
	//
	//	SDL_QueryTexture(fullScreenOnTexture, NULL, NULL, &fullScreenOnRect.w, &fullScreenOnRect.h);
	//	fullScreenOnRect.x = 15;
	//	fullScreenOnRect.y = musicOnRect.y + musicOnRect.h + 20;
	//	pos[16] = fullScreenOnRect;
	//#pragma endregion fullscreenOn
	//#pragma region fullscreenOff
	//	SDL_Surface* fullScreenOffButton = TTF_RenderText_Blended(textFont, "Fullscreen - Off", textColor);
	//	fullScreenOffTexture = SurfaceToTexture(fullScreenOffButton);
	//
	//	SDL_QueryTexture(fullScreenOffTexture, NULL, NULL, &fullScreenOffRect.w, &fullScreenOffRect.h);
	//	fullScreenOffRect.x = 15;
	//	fullScreenOffRect.y = musicOnRect.y + musicOnRect.h + 20;
	//	pos[16] = fullScreenOffRect;
	//#pragma endregion fullscreenOff


}
// Convert an SDL_Surface to SDL_Texture. We've done this before, so I'll keep it short
SDL_Texture* PauseState::SurfaceToTexture(SDL_Surface* surf)
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface(renderer, surf);

	SDL_FreeSurface(surf);

	return text;
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

	CreateTextTextures();

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

	background = LTexture();
	background.loadFromFile(gsm->GetBehaviour()->GetRenderer(), "menu.jpg");
	backgroundRect.h = background.getHeight();
	backgroundRect.w = background.getWidth();
	backgroundRect.x = 0;
	backgroundRect.y = 0;

	// Set color of renderer to red
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
}


PauseState::~PauseState()
{
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

void PauseState::Quit(){
	gsm->PopState();
	gsm->ChangeGameState();
}

void PauseState::HandleMouseEvents(SDL_Event mainEvent)
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
					if (menuState == pauseMenu){
						SoundBank::GetInstance()->Play(SoundEffectType::CORRECT);
						SoundBank::GetInstance()->StopMusic();
						gsm->ChangeGameState();

						quit = true;
					}
					break;
					//item 2, mainmenu help
				case 1:
					if (menuState == pauseMenu){
						SoundBank::GetInstance()->Play(SoundEffectType::CORRECT);
						menuState = helpMenu;
					}
					break;
					//item 3,mainmenu quit
				case 2:
					if (menuState == pauseMenu){
						Quit();
					}
					break;
					//item 6, backtomain
				case 6:
					if (menuState != pauseMenu)
					{
						SoundBank::GetInstance()->Play(SoundEffectType::CORRECT);
						menuState = pauseMenu;
					}
					break;
					//item 10, mainmenu options
				case 10:
					if (menuState == pauseMenu) {
						SoundBank::GetInstance()->Play(SoundEffectType::CORRECT);
						menuState = optionsMenu;
					}
					break;
					//item 11 & 13, sfx on
				case 11:
					if (menuState == optionsMenu) {
						SoundBank::GetInstance()->DisableOrEnableSFX();
						SoundBank::GetInstance()->Play(SoundEffectType::CORRECT);
						menuState = optionsMenu;
					}
					break;
					//item 12 & 14, music on
				case 12:
					if (menuState == optionsMenu) {
						SoundBank::GetInstance()->DisableOrEnableMusic(SoundBgmType::TESTBGM1);
						SoundBank::GetInstance()->Play(SoundEffectType::CORRECT);
						menuState = optionsMenu;
					}
					break;
				}
			}
		}
		break;
	}
}

void PauseState::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events)
{
	//std::cout << "Key events not implemented yet";
}

void PauseState::Update(float dt){
	/*while (!quit){

	HandleEvents();

	Draw();
	}*/
}
void PauseState::Draw(){
	SDL_RenderClear(renderer);

	background.render(renderer, 0, 0, &backgroundRect);

	switch (menuState){
		//mainmenu
	case pauseMenu:
		loadPauseMenu();
		break;
		//helpmenu
	case helpMenu:
		loadHelpMenu();
		break;
	case optionsMenu:
		LoadOptionsMenu();
		break;
	}
	SDL_RenderPresent(renderer);
}