#include "EditorSubState.h"

const int renderItems = 4;

void EditorSubState::Init(GameStateManager *gsm){
	this->gsm = gsm;
	if (!InitEverything()){
		std::cout << "-1";
	}
	PlayState* playState = (PlayState*)gsm->GetPreviousState();
	text = "";
	MakeBackToEditorText(textColor);
	MakeSubMenuTitle(textColor);
	MakePlayText(textColor);
	MakeSaveNewText(textColor);
	MakeSaveSameText(textColor);
	MakeBackToMainText(textColor);
	MakeInputText(textColor);
}

EditorSubState::EditorSubState()
{
	textColor = { 255, 255, 255, 255 }; // white
	hoverTextColor = { 255, 0, 0, 255 }; // red
	pos.resize(renderItems);
}
void EditorSubState::loadQuitMenu(){
	SDL_RenderCopy(renderer, quitTexture, nullptr, &quitRect);
	SDL_RenderCopy(renderer, gameoverTitleTexture, nullptr, &gameoverTitleRect);
	SDL_RenderCopy(renderer, playTexture, nullptr, &playRect);
	SDL_RenderCopy(renderer, saveNewTexture, nullptr, &saveNewRect);
	SDL_RenderCopy(renderer, saveSameTexture, nullptr, &saveSameRect);
	SDL_RenderCopy(renderer, inputTexture, nullptr, &inputRect);
	SDL_RenderCopy(renderer, backToMainTexture, nullptr, &backToMainRect);
}

bool EditorSubState::SetupTTF(const std::string &fontName, const std::string &fontName2)
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

void EditorSubState::MakeBackToEditorText(SDL_Color color)
{
	SDL_Surface* quit = TTF_RenderText_Blended(textFont, "Back To editor", color);
	quitTexture = SurfaceToTexture(quit);

	SDL_QueryTexture(quitTexture, NULL, NULL, &quitRect.w, &quitRect.h);
	quitRect.x = 5;
	quitRect.y = 5;
	pos[0] = quitRect;
}

void EditorSubState::MakePlayText(SDL_Color color)
{
	SDL_Surface* play = TTF_RenderText_Blended(textFont, "Play Level", color);
	playTexture = SurfaceToTexture(play);

	SDL_QueryTexture(playTexture, NULL, NULL, &playRect.w, &playRect.h);
	playRect.x = 15;
	playRect.y = 255;
	pos[1] = playRect;
}

void EditorSubState::MakeSaveNewText(SDL_Color color)
{
	SDL_Surface* saveNew = TTF_RenderText_Blended(textFont, "Save with new name: ", color);
	saveNewTexture = SurfaceToTexture(saveNew);

	SDL_QueryTexture(saveNewTexture, NULL, NULL, &saveNewRect.w, &saveNewRect.h);
	saveNewRect.x = 15;
	saveNewRect.y = playRect.y + playRect.h + 20;
	pos[2] = saveNewRect;
}

void EditorSubState::MakeSaveSameText(SDL_Color color)
{
	SDL_Surface* saveSame = TTF_RenderText_Blended(textFont, "Save with same name", color);
	saveSameTexture = SurfaceToTexture(saveSame);

	SDL_QueryTexture(saveSameTexture, NULL, NULL, &saveSameRect.w, &saveSameRect.h);
	saveSameRect.x = 15;
	saveSameRect.y = saveNewRect.y + saveNewRect.h + 20;
	pos[3] = saveSameRect;
}
void EditorSubState::MakeBackToMainText(SDL_Color color)
{
	SDL_Surface* exit = TTF_RenderText_Blended(textFont, "Back To main-menu", color);
	backToMainTexture = SurfaceToTexture(exit);

	SDL_QueryTexture(backToMainTexture, NULL, NULL, &backToMainRect.w, &backToMainRect.h);
	backToMainRect.x = 15;
	backToMainRect.y = saveSameRect.h + saveSameRect.y + 20;;
	pos[4] = backToMainRect;
}
void EditorSubState::MakeInputText(SDL_Color color){
	//const char* temp = text.c_str();
	SDL_Surface* input = TTF_RenderText_Blended(textFont, text.c_str(), color);
	inputTexture = SurfaceToTexture(input);

	SDL_QueryTexture(inputTexture, NULL, NULL, &inputRect.w, &inputRect.h);
	inputRect.x = saveNewRect.x + saveNewRect.w + 5;
	inputRect.y = saveNewRect.y;
	pos[5] = inputRect;
}
void EditorSubState::MakeSubMenuTitle(SDL_Color color){
	SDL_Surface* mainTitle = TTF_RenderText_Blended(titleFont, "Level Editor", color);
	gameoverTitleTexture = SurfaceToTexture(mainTitle);

	SDL_QueryTexture(gameoverTitleTexture, NULL, NULL, &gameoverTitleRect.w, &gameoverTitleRect.h);
	gameoverTitleRect.x = 540 - (gameoverTitleRect.w / 2);
	gameoverTitleRect.y = 5;
	pos[6] = gameoverTitleRect;
}
// Convert an SDL_Surface to SDL_Texture. We've done this before, so I'll keep it short
SDL_Texture* EditorSubState::SurfaceToTexture(SDL_Surface* surf)
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface(renderer, surf);

	SDL_FreeSurface(surf);

	return text;
}
bool EditorSubState::InitEverything()
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
bool EditorSubState::InitSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}
bool EditorSubState::CreateRenderer()
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
void EditorSubState::SetupRenderer()
{
	// Set size of renderer to the same as window
	//SDL_RenderSetLogicalSize(renderer, windowRect.w, windowRect.h);

	parallaxBackground = new ParallaxBackground(gsm->GetBehaviour()->GetRenderer(), 1);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-back-trees.png", 0, 0.9f, 255);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-lights.png", 0, 0.7f, 120); //cool transparency feature
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-middle-trees.png", 0, 1.2f, 255);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-front-trees.png", 0, 1.5f, 255);
}

void EditorSubState::Cleanup(){
	// Clean up font
	TTF_CloseFont(titleFont);
	TTF_CloseFont(textFont);
}

void EditorSubState::Resume() {}

void EditorSubState::Pause() {}

void EditorSubState::Quit(){
	SDL_StopTextInput();
	gsm->PopPrevState();
	gsm->PopState();
	MenuState* tempState = (MenuState*)gsm->GetCurrentState();
	tempState->updateMenu(MenuEnum::Previous);
}

void EditorSubState::Highlight(int item){
	switch (item){
	case -1:
	{
		MakeBackToEditorText(textColor);
		MakePlayText(textColor);
		MakeSaveNewText(textColor);
		MakeSaveSameText(textColor);
		MakeBackToMainText(textColor);
		break;
	}
	case 0:
	{
		MakeBackToEditorText(hoverTextColor);
		break;
	}
	case 1:
	{
		MakePlayText(hoverTextColor);
		break;
	}
	case 2:
	{
		MakeSaveNewText(hoverTextColor);
		break;
	}
	case 3:
	{
		MakeSaveSameText(hoverTextColor);
		break;
	}
	case 4:
	{
		MakeBackToMainText(hoverTextColor);
		break;
	}

	}
}
void EditorSubState::HandleMouseEvents(SDL_Event mainEvent)
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
				case 0:
					SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
					gsm->PopState();
					/*SoundBank::GetInstance()->StopMusic();

					quit = true;
					Quit();*/
					break;
				case 1:
					SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
					/*SoundBank::GetInstance()->StopMusic();

					quit = true;
					Quit();
					break;*/
				case 2:
					SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
					/*SoundBank::GetInstance()->StopMusic();

					quit = true;
					Quit();*/
					break;
				case 3:
					SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
					//gebruiken om op te slaan. todo

					LevelFactory::SaveLevel(static_cast<EditorState*>(gsm->GetPreviousState())->GetLevel(), (static_cast<EditorState*>(gsm->GetPreviousState())->GetLevelPath()));
					/*SoundBank::GetInstance()->StopMusic();

					quit = true;
					Quit();*/
					break;
				case 4:
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

void EditorSubState::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events)
{
	bool backspaced = false;
	for (auto it = _events->begin(); it != _events->end(); ++it){

		if (it->second)
		{
			switch (it->first){
			case SDLK_BACKSPACE:
				if (text.length() > 0 && !backspaced){
					text = text.substr(0, text.length() - 1);
					backspaced = true;
				}
				break;
			}
		}
	}
}

void EditorSubState::HandleTextInputEvents(SDL_Event event)
{
	switch (event.type){
	case SDL_TEXTINPUT:
		if (/*event.type == SDL_KEYDOWN && */event.key.keysym.sym == SDLK_BACKSPACE && text.length() > 0){
			text = text.substr(0, text.length() - 1);
		}
		else if (SDL_TEXTINPUT){
			text += event.text.text;
		}
		break;
	}
}

void EditorSubState::Move(float dt) {
	//no entities to move
}

void EditorSubState::Update(float dt, float manipulatorSpeed){
	//nothing to update
}

void EditorSubState::Draw(float dt, float manipulatorSpeed){
	SDL_RenderClear(renderer);
	parallaxBackground->Draw();
	loadQuitMenu();
	SDL_RenderPresent(renderer);
}

EditorSubState::~EditorSubState()
{
	Cleanup();
}
