#include "GameOverState.h"

const int renderItems = 4;


void GameOverState::Init(GameStateManager *gsm){
	this->gsm = gsm;
	if (!InitEverything()){
		std::cout << "-1";
	}
	highscoreConfig = highscoreConfig;
	PlayState* playState = (PlayState*)gsm->GetPreviousState();
	score = playState->GetPlayer()->GetScore();
	time = playState->GetPlayer()->GetPlayTime();
	text = "";
	MakeBackToMainText(textColor);
	MakeGameOverTitle(textColor);
	MakeScoreText(textColor);
	MakeTimeText(textColor);
	MakeSave(textColor);
	MakeSaveText(textColor);
	MakeInputText(textColor);
	SoundBank::GetInstance()->PlayBGM(SoundBgmType::TESTBGM1);

	SoundBank::GetInstance()->PlaySFX(SoundEffectType::GAMEOVER);
	SDL_Delay(2000);
	/*SoundBank::GetInstance()->Play(SoundEffectType::YOU);
	SDL_Delay(2000);*/
	SoundBank::GetInstance()->PlaySFX(SoundEffectType::LOSE);
	SDL_StartTextInput();
}

GameOverState::GameOverState()
{
	textColor = { 255, 255, 255, 255 }; // white
	hoverTextColor = { 255, 0, 0, 255 }; // red
	pos.resize(renderItems);
	lockButtonTicks = SDL_GetTicks();
}

void GameOverState::loadQuitMenu(){
	SDL_RenderCopy(renderer, quitTexture, nullptr, &quitRect);
	SDL_RenderCopy(renderer, gameoverTitleTexture, nullptr, &gameoverTitleRect);
	SDL_RenderCopy(renderer, scoreTexture, nullptr, &scoreRect);
	SDL_RenderCopy(renderer, timeTexture, nullptr, &timeRect);
	SDL_RenderCopy(renderer, saveTexture, nullptr, &saveRect);
	SDL_RenderCopy(renderer, saveTextTexture, nullptr, &saveTextRect);
	SDL_RenderCopy(renderer, inputTexture, nullptr, &inputRect);
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
	pos[6] = gameoverTitleRect;
}
void GameOverState::MakeScoreText(SDL_Color color){
	string string = "You scored " + to_string(score) + " points so far!";
	SDL_Surface* score = TTF_RenderText_Blended(textFont, string.c_str(), color);
	scoreTexture = SurfaceToTexture(score);

	SDL_QueryTexture(scoreTexture, NULL, NULL, &scoreRect.w, &scoreRect.h);
	scoreRect.x = 15;
	scoreRect.y = quitRect.y + quitRect.h + 40;
	pos[2] = scoreRect;
}
void GameOverState::MakeTimeText(SDL_Color color){
	string string = "You played " + to_string(time.at(0)) + " minutes and " + to_string(time.at(1)) + " seconds so far!";
	SDL_Surface* time = TTF_RenderText_Blended(textFont, string.c_str(), color);
	timeTexture = SurfaceToTexture(time);

	SDL_QueryTexture(timeTexture, NULL, NULL, &timeRect.w, &timeRect.h);
	timeRect.x = 15;
	timeRect.y = scoreRect.y + scoreRect.h + 40;
	pos[3] = timeRect;
}
void GameOverState::MakeInputText(SDL_Color color){
	//const char* temp = text.c_str();
	SDL_Surface* input = TTF_RenderText_Blended(textFont, text.c_str(), color);
	inputTexture = SurfaceToTexture(input);

	SDL_QueryTexture(inputTexture, NULL, NULL, &inputRect.w, &inputRect.h);
	inputRect.x = saveTextRect.x + saveTextRect.w + 5;
	inputRect.y = timeRect.y + timeRect.h + 40;
	pos[4] = inputRect;
}
void GameOverState::MakeSave(SDL_Color color){
	//const char* temp = text.c_str();
	SDL_Surface* save = TTF_RenderText_Blended(textFont, "->Opslaan<-", color);
	saveTexture = SurfaceToTexture(save);

	SDL_QueryTexture(saveTexture, NULL, NULL, &saveRect.w, &saveRect.h);
	saveRect.x = 15;
	saveRect.y = timeRect.y + timeRect.h + 40;
	pos[1] = saveRect;
}
void GameOverState::MakeSaveText(SDL_Color color){
	//const char* temp = text.c_str();
	SDL_Surface* savetext = TTF_RenderText_Blended(textFont, " onder deze naam: ", color);
	saveTextTexture = SurfaceToTexture(savetext);

	SDL_QueryTexture(saveTextTexture, NULL, NULL, &saveTextRect.w, &saveTextRect.h);
	saveTextRect.x = saveRect.x + saveRect.w + 5;
	saveTextRect.y = timeRect.y + timeRect.h + 40;
	pos[5] = saveTextRect;
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

	parallaxBackground = new ParallaxBackground(gsm->GetBehaviour()->GetRenderer(), 1);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-back-trees.png", 0, 0.9f, 255);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-lights.png", 0, 0.7f, 120); //cool transparency feature
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-middle-trees.png", 0, 1.2f, 255);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-front-trees.png", 0, 1.5f, 255);
}


GameOverState::~GameOverState()
{
	Cleanup();
}

void GameOverState::Cleanup(){
	// Clean up font
	TTF_CloseFont(titleFont);
	TTF_CloseFont(textFont);
}

void GameOverState::Resume() {}

void GameOverState::Pause() {}

void GameOverState::Quit(){
	SDL_StopTextInput();
	gsm->PopPrevState();
	gsm->PopState();
//	MenuState* tempState = (MenuState*)gsm->GetCurrentState();
//	tempState->updateMenu(MenuEnum::Previous);
}

void GameOverState::Highlight(int item){
	switch (item){
	case -1:
	{
		MakeBackToMainText(textColor);
		MakeSave(textColor);
		break;
	}
	case 0:
	{
		MakeBackToMainText(hoverTextColor);
		break;
	}
	case 1:
	{
		MakeSave(hoverTextColor);
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
					Quit();
					break;
				case 1:
					SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
					SoundBank::GetInstance()->StopMusic();
					//save highscore
					//string tempMin = to_string(time.at(0));
					//string tempSec = to_string(time.at(1));
					highscoreConfig.SaveHighscore(text, score, to_string(time.at(0)), to_string(time.at(1)));
					//vector<Score>* temp = highscoreConfig.GetHighscore();
					quit = true;
					Quit();
					break;
				}
			}
		}
	}
}

void GameOverState::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events)
{
	bool backspaced = false;
	for (auto it = _events->begin(); it != _events->end(); ++it){

		if (it->second)
		{
			switch (it->first){
			case SDLK_BACKSPACE:
				if (text.length() > 0 && !backspaced){
					if (lockButtonTicks + 100 < SDL_GetTicks()) {
						text = text.substr(0, text.length() - 1);
						backspaced = true;
						MakeInputText(textColor);

						lockButtonTicks = SDL_GetTicks();
					}
				}
				break;
			}
		}
	}
}

void GameOverState::HandleTextInputEvents(SDL_Event event)
{
	switch (event.type){
	case SDL_TEXTINPUT:
		if (/*event.type == SDL_KEYDOWN && */event.key.keysym.sym == SDLK_BACKSPACE && text.length() > 0){
			text = text.substr(0, text.length() - 1);
		}
		else if (SDL_TEXTINPUT){
			text += event.text.text;
		}
		MakeInputText(textColor);
		break;
	}
}

void GameOverState::Update(float dt, float manipulatorSpeed){
	//empty, move on
}

void GameOverState::Draw(float dt, float manipulatorSpeed){
	SDL_RenderClear(renderer);
	parallaxBackground->Draw();
	loadQuitMenu();
	SDL_RenderPresent(renderer);
}