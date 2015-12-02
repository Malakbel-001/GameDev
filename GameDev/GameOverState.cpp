#include "GameOverState.h"

const int renderItems = 18;


void GameOverState::Init(GameStateManager *gsm){
	this->gsm = gsm;
	if (!InitEverything()){
		std::cout << "-1";
	}
	MakeBackToMainText(textColor);
	MakeGameOverTitle(textColor);
	SoundBank::GetInstance()->PlayBGM(SoundBgmType::TESTBGM1);

	SoundBank::GetInstance()->PlaySFX(SoundEffectType::GAMEOVER);
	SDL_Delay(2000);
	/*SoundBank::GetInstance()->Play(SoundEffectType::YOU);
	SDL_Delay(2000);*/
	SoundBank::GetInstance()->PlaySFX(SoundEffectType::LOSE);
	Update(0);
}

GameOverState::GameOverState()
{
	textColor = { 255, 255, 255, 255 }; // white
	hoverTextColor = { 255, 0, 0, 255 };
	pos.resize(renderItems);
}

void GameOverState::loadQuitMenu(){
	SDL_RenderCopy(renderer, quitTexture, nullptr, &quitRect);
	SDL_RenderCopy(renderer, gameoverTitleTexture, nullptr, &gameoverTitleRect);
}

// Initialization ++
// ==================================================================
bool GameOverState::SetupTTF(const std::string &fontName, const std::string &fontName2)
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
void GameOverState::MakeBackToMainText(SDL_Color color)
{
	SDL_Surface* quit = TTF_RenderText_Blended(textFont, "Back To main-menu", color);
	quitTexture = SurfaceToTexture(quit);

	SDL_QueryTexture(quitTexture, NULL, NULL, &quitRect.w, &quitRect.h);
	quitRect.x = 15;
	quitRect.y = 255;
	pos[0] = quitRect;
}
void GameOverState::MakeGameOverTitle(SDL_Color color){
	SDL_Surface* mainTitle = TTF_RenderText_Blended(titleFont, "Game Over", color);
	gameoverTitleTexture = SurfaceToTexture(mainTitle);

	SDL_QueryTexture(gameoverTitleTexture, NULL, NULL, &gameoverTitleRect.w, &gameoverTitleRect.h);
	gameoverTitleRect.x = 540 - (gameoverTitleRect.w / 2);
	gameoverTitleRect.y = 5;
	pos[1] = gameoverTitleRect;
}

// Convert an SDL_Surface to SDL_Texture. We've done this before, so I'll keep it short
SDL_Texture* GameOverState::SurfaceToTexture(SDL_Surface* surf)
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface(renderer, surf);

	SDL_FreeSurface(surf);

	return text;
}
bool GameOverState::InitEverything()
{
	if (!InitSDL())
		return false;

	if (!CreateRenderer())
		return false;

	SetupRenderer();

	if (!SetupTTF("28 Days Later.ttf", "armalite_rifle.ttf"))
		return false;

	return true;
}
bool GameOverState::InitSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}
bool GameOverState::CreateRenderer()
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
void GameOverState::SetupRenderer()
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


GameOverState::~GameOverState()
{
}

void GameOverState::Cleanup(){
	// Clean up font
	TTF_CloseFont(titleFont);
	TTF_CloseFont(textFont);
}

void GameOverState::Resume() {}

void GameOverState::Pause() {}

void GameOverState::Quit(){
	gsm->PopState();
	gsm->ChangeGameState();
}

void GameOverState::Highlight(int item){
	switch (item){
	case -1:
	{
		MakeBackToMainText(textColor);
		break;
	}
	case 0:
	{
		MakeBackToMainText(hoverTextColor);
		break;
	}
	}
}
void GameOverState::HandleMouseEvents(SDL_Event mainEvent)
{
	switch (mainEvent.type)
	{
	case SDL_QUIT:
		quit = true;
		break;
	case SDL_MOUSEMOTION:
	{hoverX = mainEvent.motion.x;
	hoverY = mainEvent.motion.y;
	for (int ii = 0; ii < 6; ii++)
	{
		if (hoverX >= pos[ii].x && hoverX <= pos[ii].x + pos[ii].w && hoverY >= pos[ii].y && hoverY <= pos[ii].y + pos[ii].h){
			Highlight(ii);
			break;
		}
		else {
			Highlight(-1);

		}
	}
	break;
	}
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

void GameOverState::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events)
{
	//std::cout << "Key events not implemented yet";
}

void GameOverState::Update(float dt){
	/*while (!quit){

	HandleEvents();

	Draw();
	}*/
}

void GameOverState::Draw(){
	SDL_RenderClear(renderer);

	background.render(renderer, 0, 0,0, &backgroundRect);
	loadQuitMenu();
	SDL_RenderPresent(renderer);
}