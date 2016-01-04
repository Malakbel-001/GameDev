#include "VictoryState.h"

//const int renderItems = 18;

void VictoryState::Init(GameStateManager *gsm){
	this->gsm = gsm;
	if (!InitEverything()){
		std::cout << "-1";
	}
	PlayState* playState = (PlayState*)gsm->GetPreviousState();
	score = playState->GetPlayer()->GetScore();
	MakeNextLevelText(textColor);
	MakeQuitText(textColor);
	MakeVictorytitle(textColor);
	MakeScoreText(textColor);
	SoundBank::GetInstance()->PlayBGM(SoundBgmType::TESTBGM1);

//	SoundBank::GetInstance()->PlaySFX(SoundEffectType::GAMEOVER);
	/*SDL_Delay(4000);
	SoundBank::GetInstance()->PlaySFX(SoundEffectType::YOU);*/
	//SDL_Delay(2000);
	SoundBank::GetInstance()->PlaySFX(SoundEffectType::WIN);
}

VictoryState::VictoryState()
{
	textColor = { 255, 255, 255, 255 }; // white	
	hoverTextColor = { 255, 0, 0, 255 }; // red
	pos.resize(renderItems);
}

void VictoryState::loadQuitMenu(){
	SDL_RenderCopy(renderer, quitTexture, nullptr, &quitRect);
	SDL_RenderCopy(renderer, nextTexture, nullptr, &nextRect);
	SDL_RenderCopy(renderer, victoryTitleTexture, nullptr, &victoryTitleRect);
	SDL_RenderCopy(renderer, scoreTexture, nullptr, &scoreRect);
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
void VictoryState::MakeNextLevelText(SDL_Color color){
	SDL_Surface* next = TTF_RenderText_Blended(textFont, "Next Level", color);
	nextTexture = SurfaceToTexture(next);

	SDL_QueryTexture(nextTexture, NULL, NULL, &nextRect.w, &nextRect.h);
	nextRect.x = 15;
	nextRect.y = 255;
	pos[0] = nextRect;
}
void VictoryState::MakeQuitText(SDL_Color color){
	SDL_Surface* quit = TTF_RenderText_Blended(textFont, "Back To main-menu", color);
	quitTexture = SurfaceToTexture(quit);

	SDL_QueryTexture(quitTexture, NULL, NULL, &quitRect.w, &quitRect.h);
	quitRect.x = 15;
	quitRect.y = nextRect.y + nextRect.h + 20;
	pos[1] = quitRect;
	}

void VictoryState::MakeVictorytitle(SDL_Color color){
	SDL_Surface* mainTitle = TTF_RenderText_Blended(titleFont, "Victory", color);
	victoryTitleTexture = SurfaceToTexture(mainTitle);

	SDL_QueryTexture(victoryTitleTexture, NULL, NULL, &victoryTitleRect.w, &victoryTitleRect.h);
	victoryTitleRect.x = 540 - (victoryTitleRect.w / 2);
	victoryTitleRect.y = 5;
	pos[2] = victoryTitleRect;
}
void VictoryState::MakeScoreText(SDL_Color color){
	string string = "You scored " + to_string(score) + " points so far!";
	SDL_Surface* score = TTF_RenderText_Blended(textFont, string.c_str(), color);
	scoreTexture = SurfaceToTexture(score);

	SDL_QueryTexture(scoreTexture, NULL, NULL, &scoreRect.w, &scoreRect.h);
	scoreRect.x = 15;
	scoreRect.y = quitRect.y + quitRect.h + 40;
	pos[3] = scoreRect;
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
	Cleanup();
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
	gsm->PopState();
	MenuState* tempState = (MenuState*)gsm->GetCurrentState();
	tempState->updateMenu(MenuEnum::Previous);

}

void VictoryState::Highlight(int item){
	switch (item){
	case -1:
	{
		MakeNextLevelText(textColor);
		MakeQuitText(textColor);
		break;
	}
	case 0:
	{
		MakeNextLevelText(hoverTextColor);
		break;
	}
	case 1:
	{
		MakeQuitText(hoverTextColor);
		break;
	}
	}
}

void VictoryState::Next(){
	if(PlayState* state = dynamic_cast <PlayState*>(gsm->GetPreviousState()))
	{
		state->SetCurrentLevel(LevelFactory::GetNextLevel(state->GetCurrentLevel(), state));
		gsm->PopState();
	}	
}

void VictoryState::HandleMouseEvents(SDL_Event mainEvent)
{
	switch (mainEvent.type)
	{
	case SDL_QUIT:
		quit = true;
		break;
	case SDL_MOUSEMOTION:
	{hoverX = mainEvent.motion.x;
	hoverY = mainEvent.motion.y;
	for (int ii = 0; ii < renderItems; ii++)
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
					Next();
					break;
				case 1:
					SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
					SoundBank::GetInstance()->StopMusic();

					quit = true;
					Quit();
					break;
				}
			}
			
		}
	}
}

void VictoryState::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events)
{
	//std::cout << "Key events not implemented yet";
}

void VictoryState::Update(float dt, float manipulatorSpeed){
	//nothing to see here, move on
}

void VictoryState::Draw(float dt, float manipulatorSpeed){
	SDL_RenderClear(renderer);

	background.render(renderer, 0, 0,0, &backgroundRect);
	loadQuitMenu();
	SDL_RenderPresent(renderer);
}