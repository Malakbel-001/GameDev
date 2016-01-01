#include "MainMenu.h"
#include "MenuState.h"
#include "Game.h"
MainMenu::MainMenu(MenuState* menu, SDL_Renderer* renderer, TTF_Font* textfont, TTF_Font* titlefont)
{
	textColor = { 255, 255, 255, 255 }; // white;
	hoverTextColor = { 255, 0, 0, 255 }; // red
	this->menu = menu;
	this->renderer = renderer;
	this->textFont = textfont;
	this->titleFont = titlefont;
	MakePlayText(textColor);
	MakeLevelEditorText(textColor);
	MakeHighscoreText(textColor);
	MakeHelpText(textColor);
	MakeCreditText(textColor);
	MakeOptionText(textColor);
	MakeQuitText(textColor);	
	MakeMainTitle(textColor);
}

void MainMenu::Init(){

}

void MainMenu::MakePlayText(SDL_Color color){
	SDL_Surface* play = TTF_RenderText_Blended(textFont, "Play", color);
	playTexture = SurfaceToTexture(play);

	SDL_QueryTexture(playTexture, NULL, NULL, &solidRect.w, &solidRect.h);
	solidRect.x = 15;
	solidRect.y = 225;
	pos[0] = solidRect;
}

void MainMenu::MakeLevelEditorText(SDL_Color color) {
	SDL_Surface* editor = TTF_RenderText_Blended(textFont, "Level Editor", color);
	editorTexture = SurfaceToTexture(editor);

	SDL_QueryTexture(editorTexture, NULL, NULL, &editorRect.w, &editorRect.h);
	editorRect.x = 15;
	editorRect.y = solidRect.y + solidRect.h + 20;
	pos[6] = editorRect;
}

void MainMenu::MakeHighscoreText(SDL_Color color){
	SDL_Surface* highscore = TTF_RenderText_Blended(textFont, "Highscore", color);
	highscoreTexture = SurfaceToTexture(highscore);

	SDL_QueryTexture(highscoreTexture, NULL, NULL, &highscoreRect.w, &highscoreRect.h);
	highscoreRect.x = 15;
	highscoreRect.y = editorRect.y + editorRect.h + 20;
	pos[5] = highscoreRect;
}

void MainMenu::MakeHelpText(SDL_Color color){
	SDL_Surface* help = TTF_RenderText_Blended(textFont, "Help", color);
	helpTexture = SurfaceToTexture(help);

	SDL_QueryTexture(helpTexture, NULL, NULL, &blendedRect.w, &blendedRect.h);
	blendedRect.x = 15;
	blendedRect.y = highscoreRect.y + highscoreRect.h + 20;
	pos[1] = blendedRect;
}

void MainMenu::MakeQuitText(SDL_Color color){
	SDL_Surface* quit = TTF_RenderText_Blended(textFont, "Quit", color);
	quitTexture = SurfaceToTexture(quit);

	SDL_QueryTexture(quitTexture, NULL, NULL, &shadedRect.w, &shadedRect.h);
	shadedRect.x = 15;
	shadedRect.y = optionsRect.y + optionsRect.h + 20;
	pos[4] = shadedRect;
}

void MainMenu::MakeCreditText(SDL_Color color){
	SDL_Surface* credit = TTF_RenderText_Blended(textFont, "Credits", color);
	creditTexture = SurfaceToTexture(credit);

	SDL_QueryTexture(creditTexture, NULL, NULL, &creditRect.w, &creditRect.h);
	creditRect.x = 15;
	creditRect.y = blendedRect.y + blendedRect.h + 20;;
	pos[2] = creditRect;
}
	
void MainMenu::MakeOptionText(SDL_Color color){
	SDL_Surface* options = TTF_RenderText_Blended(textFont, "Options", color);
	optionsTexture = SurfaceToTexture(options);

	SDL_QueryTexture(optionsTexture, NULL, NULL, &optionsRect.w, &optionsRect.h);
	optionsRect.x = 15;
	optionsRect.y = creditRect.y + creditRect.h + 20;
	pos[3] = optionsRect;
}

void MainMenu::MakeMainTitle(SDL_Color color){
	SDL_Surface* mainTitle = TTF_RenderText_Blended(titleFont, "Jark Hunt", color);
	mainTitleTexture = SurfaceToTexture(mainTitle);

	SDL_QueryTexture(mainTitleTexture, NULL, NULL, &mainTitleRect.w, &mainTitleRect.h);
	mainTitleRect.x = 540 - (mainTitleRect.w / 2);
	mainTitleRect.y = 5;
	pos[7] = mainTitleRect;
}

SDL_Texture* MainMenu::SurfaceToTexture(SDL_Surface* surf)
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface(renderer, surf);

	SDL_FreeSurface(surf);

	return text;
}

void MainMenu::SetupRenderer(){

}

void MainMenu::Draw(){
	SDL_RenderCopy(renderer, playTexture, nullptr, &solidRect);
	SDL_RenderCopy(renderer, editorTexture, nullptr, &editorRect);
	SDL_RenderCopy(renderer, highscoreTexture, nullptr, &highscoreRect);
	SDL_RenderCopy(renderer, helpTexture, nullptr, &blendedRect);
	SDL_RenderCopy(renderer, optionsTexture, nullptr, &optionsRect); //NEW
	SDL_RenderCopy(renderer, quitTexture, nullptr, &shadedRect);
	SDL_RenderCopy(renderer, creditTexture, nullptr, &creditRect);
	SDL_RenderCopy(renderer, mainTitleTexture, nullptr, &mainTitleRect);
}

void MainMenu::Update(float dt){

}

void MainMenu::Highlight(int item){
	switch (item){
		case -1:
		{
			MakePlayText(textColor);
			MakeLevelEditorText(textColor);
			MakeHighscoreText(textColor);
			MakeHelpText(textColor);
			MakeQuitText(textColor);
			MakeCreditText(textColor);
			MakeOptionText(textColor);
			break;
		}
		case 0:
		{
			MakePlayText(hoverTextColor);
			break;
		}
		case 1:
		{
			MakeHelpText(hoverTextColor);
			break;
		}
		case 2:
		{
			MakeCreditText(hoverTextColor);
			break;
		}
		case 3:
		{
			MakeOptionText(hoverTextColor);
			break;
		}
		case 4:
		{
			MakeQuitText(hoverTextColor);
			break;
		}
		case 5:
		{
			MakeHighscoreText(hoverTextColor);
			break;
		}
		case 6:
		{
			MakeLevelEditorText(hoverTextColor);
			break;
		}
		//case 7 does not need hoverTextColor
	}
}

void MainMenu::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events)
{
	//std::cout << "Key events not implemented yet";
}

void MainMenu::HandleMouseEvents(SDL_Event mainEvent)
{
	switch (mainEvent.type)
	{

		case SDL_MOUSEMOTION:
		{
			hoverX = mainEvent.motion.x;
			hoverY = mainEvent.motion.y;
			for (int ii = 0; ii < (sizeof(pos) / sizeof(*pos)); ii++) //(sizeof(pos) / sizeof(*pos)) -> size of pos array
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
		for (int i = 0; i < (sizeof(pos) / sizeof(*pos)); i++) //(sizeof(pos) / sizeof(*pos)) -> size of pos array
		{
			if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h){
				switch (i){
					case 0:
						//play
						SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
						menu->updateMenu(MenuEnum::Play);
						break;
					case 1:
						//help
						SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
						menu->updateMenu(MenuEnum::Help);
						break;
					case 2:
						//credits
						SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
						menu->updateMenu(MenuEnum::Credits);
						break;
					case 3:
						//options
						SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
						menu->updateMenu(MenuEnum::Options);
						break;
					case 4:
						//quit
						SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
						Game::running = false;
						break;
					case 5:
						//highscore
						SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
						menu->updateMenu(MenuEnum::Highscore);
						break;
					case 6:
						SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
						
						//temp disabled
						menu->GetGSM()->CreateGameState(GameStateType::EditorState);

						break;
					//case 7, aka the menuTitle, does not need to be clickable
				}
			}
		}
	}
}


MainMenu::~MainMenu()
{
}
