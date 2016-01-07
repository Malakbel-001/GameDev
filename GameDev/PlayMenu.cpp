#include "PlayMenu.h"
#include "MenuState.h"

PlayMenu::PlayMenu(MenuState* menu, SDL_Renderer* renderer, TTF_Font* textfont, TTF_Font* titlefont)
{
	levelconfig = LevelConfig();
	LoadLevels();
	textColor = { 255, 255, 255, 255 }; // white
	hoverTextColor = { 255, 0, 0, 255 }; // red
	disabledTextColor = { 42, 42, 42, 255 }; // grey
	this->mainMenu = menu;
	this->renderer = renderer;
	this->textFont = textfont;
	this->titleFont = titlefont;
	MakeBackToMain(textColor);
	MakePlayTitle(textColor);
	MakeNewGame(textColor);
	MakeLevel1(textColor);
	MakeLevel2(textColor);
	MakeLevel3(textColor);
}

void PlayMenu::Init(){

}

void PlayMenu::MakeBackToMain(SDL_Color color){
	SDL_Surface* backToMain = TTF_RenderText_Blended(textFont, "Back", color);
	backToMainTexture = SurfaceToTexture(backToMain);

	SDL_QueryTexture(backToMainTexture, NULL, NULL, &backToMainRect.w, &backToMainRect.h);
	backToMainRect.x = 5;
	backToMainRect.y = 5;
	pos[0] = backToMainRect;
}

void PlayMenu::MakeNewGame(SDL_Color color){
	SDL_Surface* newGameButton = TTF_RenderText_Blended(textFont, "New Game", color);
	newGameTexture = SurfaceToTexture(newGameButton);

	SDL_QueryTexture(newGameTexture, NULL, NULL, &newGameRect.w, &newGameRect.h);
	newGameRect.x = 15;
	newGameRect.y = 225;
	pos[4] = newGameRect;
}

void PlayMenu::MakeLevel1(SDL_Color color){
	if (!levelsMap->at("Level1")){
		color = disabledTextColor;
	}
	SDL_Surface* level1Button = TTF_RenderText_Blended(textFont, "Level 1", color);
	level1Texture = SurfaceToTexture(level1Button);

	SDL_QueryTexture(level1Texture, NULL, NULL, &level1Rect.w, &level1Rect.h);
	level1Rect.x = 15;
	level1Rect.y = newGameRect.y + newGameRect.h + 20;;
	pos[1] = level1Rect;
}

void PlayMenu::MakeLevel2(SDL_Color color){
	if (!levelsMap->at("Level2")){
		color = disabledTextColor;
	}
	SDL_Surface* level2Button = TTF_RenderText_Blended(textFont, "Level 2", color);
	level2Texture = SurfaceToTexture(level2Button);

	SDL_QueryTexture(level1Texture, NULL, NULL, &level2Rect.w, &level2Rect.h);
	level2Rect.x = 15;
	level2Rect.y = level1Rect.y + level1Rect.h + 20;
	pos[2] = level2Rect;
}

void PlayMenu::MakeLevel3(SDL_Color color){
	if (!levelsMap->at("Level3")){
		color = disabledTextColor;
	}
	SDL_Surface* level3Button = TTF_RenderText_Blended(textFont, "Level 3", color);
	level3Texture = SurfaceToTexture(level3Button);

	SDL_QueryTexture(level3Texture, NULL, NULL, &level3Rect.w, &level3Rect.h);
	level3Rect.x = 15;
	level3Rect.y = level2Rect.y + level2Rect.h + 20;
	pos[3] = level3Rect;
}

void PlayMenu::MakePlayTitle(SDL_Color color){
	SDL_Surface* playtTitle = TTF_RenderText_Blended(titleFont, "Level Selector", color);
	playTitleTexture = SurfaceToTexture(playtTitle);

	SDL_QueryTexture(playTitleTexture, NULL, NULL, &playTitleRect.w, &playTitleRect.h);
	playTitleRect.x = 540 - (playTitleRect.w /2 );
	playTitleRect.y = 5;
	pos[5] = playTitleRect;
}

SDL_Texture* PlayMenu::SurfaceToTexture(SDL_Surface* surf)
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface(renderer, surf);

	SDL_FreeSurface(surf);

	return text;
}

void PlayMenu::SetupRenderer(){

}

void PlayMenu::Draw(){
	SDL_RenderCopy(renderer, playTitleTexture, nullptr, &playTitleRect);
	SDL_RenderCopy(renderer, newGameTexture, nullptr, &newGameRect);
	SDL_RenderCopy(renderer, level1Texture, nullptr, &level1Rect);
	SDL_RenderCopy(renderer, level2Texture, nullptr, &level2Rect);
	SDL_RenderCopy(renderer, level3Texture, nullptr, &level3Rect);
	SDL_RenderCopy(renderer, backToMainTexture, nullptr, &backToMainRect);
}

void PlayMenu::Update(float dt){

}

void PlayMenu::Highlight(int item){
	switch (item){
		case -1:
		{
			MakeBackToMain(textColor);
			MakePlayTitle(textColor);
			MakeLevel1(textColor);
			MakeLevel2(textColor);
			MakeLevel3(textColor);
			MakeNewGame(textColor);
			break;
		}
		case 0:
		{
			MakeBackToMain(hoverTextColor);
			break;
		}
		case 1:
		{
			MakeLevel1(hoverTextColor);
			break;
		}
		case 2:
		{
			MakeLevel2(hoverTextColor);
			break;
		}
		case 3:
		{
			MakeLevel3(hoverTextColor);
			break;
		}
		case 4:
		{
			MakeNewGame(hoverTextColor);
			break;
		}
	}
}

void PlayMenu::LoadLevels(){
	levelconfig.LoadLevels();
	if (levelconfig.GetLevels()->size() == 0){
		levelconfig.ResetLevels();
		levelsMap = levelconfig.GetLevels();
	}
	else {
		levelsMap = levelconfig.GetLevels();
	}
}

void PlayMenu::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events)
{
	//std::cout << "Key events not implemented yet";
}

void PlayMenu::HandleMouseEvents(SDL_Event mainEvent)
{
	switch (mainEvent.type)
	{

		break;
	case SDL_MOUSEMOTION:
	{hoverX = mainEvent.motion.x;
	hoverY = mainEvent.motion.y;
	for (int ii = 0; ii < 5; ii++)
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
		for (int i = 0; i < 8; i++)
		{
			if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h){
				switch (i){
				case 0:
					//back to main
					SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
						mainMenu->updateMenu(MenuEnum::Previous);
					break;
				case 1:
					//level1
					if (levelsMap->at("Level1")){
						SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
						mainMenu->GetGSM()->CreateGameState(GameStateType::LoadState, 1);
					}
					break;
				case 2:
					//level2
					if (levelsMap->at("Level2")){
						SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
						mainMenu->GetGSM()->CreateGameState(GameStateType::LoadState, 2);
					}
					break;
				case 3:
					//level3
					if (levelsMap->at("Level3")){
						SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
						mainMenu->GetGSM()->CreateGameState(GameStateType::LoadState, 3);
					}
					break;
				case 4:
					//level2
						SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
						levelconfig.ResetLevels();
						mainMenu->GetGSM()->CreateGameState(GameStateType::LoadState, 1);
					break;
				}
			}
		}
	}
}

PlayMenu::~PlayMenu()
{
}
