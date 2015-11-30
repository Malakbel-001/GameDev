#include "VictoryState.h"

const int renderItems = 18;

void VictoryState::Init(GameStateManager *gsm){
	this->gsm = gsm;
	if (!InitEverything()){
		std::cout << "-1";
	}
	SoundBank::GetInstance()->PlayBGM(SoundBgmType::TESTBGM1);

	SoundBank::GetInstance()->PlaySFX(SoundEffectType::GAMEOVER);
	/*SDL_Delay(4000);
	SoundBank::GetInstance()->PlaySFX(SoundEffectType::YOU);*/
	SDL_Delay(2000);
	SoundBank::GetInstance()->PlaySFX(SoundEffectType::WIN);
	Update(0);
}

VictoryState::VictoryState()
{
	textColor = { 255, 255, 255, 255 }; // white	
	pos.resize(renderItems);
}

void VictoryState::loadQuitMenu(){
	SDL_RenderCopy(renderer, quitTexture, nullptr, &quitRect);
	SDL_RenderCopy(renderer, victoryTitleTexture, nullptr, &victoryTitleRect);
}

// Initialization ++
// ==================================================================
bool VictoryState::SetupTTF(const std::string &fontName, const std::string &fontName2)
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
void VictoryState::CreateTextTextures()
{
#pragma region quit
	SDL_Surface* quit = TTF_RenderText_Blended(textFont, "Back To main-menu", textColor);
	quitTexture = SurfaceToTexture(quit);

	SDL_QueryTexture(quitTexture, NULL, NULL, &quitRect.w, &quitRect.h);
	quitRect.x = 15;
	quitRect.y = 255;
	pos[0] = quitRect;
#pragma endregion quit
#pragma region victorytitle
	SDL_Surface* mainTitle = TTF_RenderText_Blended(titleFont, "Victory", textColor);
	victoryTitleTexture = SurfaceToTexture(mainTitle);

	SDL_QueryTexture(victoryTitleTexture, NULL, NULL, &victoryTitleRect.w, &victoryTitleRect.h);
	victoryTitleRect.x = 540 - (victoryTitleRect.w / 2);
	victoryTitleRect.y = 5;
	pos[1] = victoryTitleRect;
#pragma endregion victorytitle
}

// Convert an SDL_Surface to SDL_Texture. We've done this before, so I'll keep it short
SDL_Texture* VictoryState::SurfaceToTexture(SDL_Surface* surf)
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface(renderer, surf);

	SDL_FreeSurface(surf);

	return text;
}
bool VictoryState::InitEverything()
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
bool VictoryState::InitSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}
bool VictoryState::CreateRenderer()
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
void VictoryState::SetupRenderer()
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


VictoryState::~VictoryState()
{
}

void VictoryState::Cleanup(){
	// Clean up font
	TTF_CloseFont(titleFont);
	TTF_CloseFont(textFont);
}

void VictoryState::Resume() {}

void VictoryState::Pause() {}

void VictoryState::Quit(){
	gsm->PopState();
	gsm->ChangeGameState();
}

void VictoryState::HandleMouseEvents(SDL_Event mainEvent)
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
					SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
					SoundBank::GetInstance()->StopMusic();

					quit = true;
					Quit();
					break;
				}
			}
			break;
		}
	}
}

void VictoryState::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events)
{
	//std::cout << "Key events not implemented yet";
}

void VictoryState::Update(float dt){
	/*while (!quit){

	HandleEvents();

	Draw();
	}*/
}

void VictoryState::Draw(){
	SDL_RenderClear(renderer);

	background.render(renderer, 0, 0,0, &backgroundRect);
	loadQuitMenu();
	SDL_RenderPresent(renderer);
}