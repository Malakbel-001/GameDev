#include "CreditMenu.h"
#include "MenuState.h"
#include "PauseState.h"
CreditMenu::CreditMenu(MenuState* menu, SDL_Renderer* renderer, TTF_Font* textfont, TTF_Font* titlefont)
{
	textColor = { 255, 255, 255, 255 }; // white;
	hoverTextColor = { 255, 0, 0, 255 }; // red
	this->mainMenu = menu;
	this->renderer = renderer;
	this->textFont = textfont;
	this->titleFont = titlefont;
	MakeBackToMain(textColor);
	MakeCreditText(textColor);
	MakeCreditTitle(textColor);
}

CreditMenu::CreditMenu(PauseState* menu, SDL_Renderer* renderer, TTF_Font* textfont, TTF_Font* titlefont)
{
	mainMenu = nullptr;
	textColor = { 255, 255, 255, 255 }; // white;
	hoverTextColor = { 255, 0, 0, 255 }; // red
	this->pauseMenu = menu;
	this->renderer = renderer;
	this->textFont = textfont;
	this->titleFont = titlefont;
	MakeBackToMain(textColor);
	MakeCreditText(textColor);
	MakeCreditTitle(textColor);
}

void CreditMenu::Init(){

}

void CreditMenu::MakeBackToMain(SDL_Color color){
	SDL_Surface* backToMain = TTF_RenderText_Blended(textFont, "Back", color);
	backToMainTexture = SurfaceToTexture(backToMain);

	SDL_QueryTexture(backToMainTexture, NULL, NULL, &backToMainRect.w, &backToMainRect.h);
	backToMainRect.x = 5;
	backToMainRect.y = 5;
	pos[0] = backToMainRect;
}

void CreditMenu::MakeCreditText(SDL_Color color){
	SDL_Surface* creditText = TTF_RenderText_Blended_Wrapped(textFont, "In dit stukje tekst bedanken wij alle spelers voor het spelen van ons spel. De makers van deze game zijn:\n-Thomas de Brouwer\n-Jeroen Guelen\n-Mark-Jan de Jong\n-Roel van Atteveld\n-Daniel Eijkelenboom", color, 1000);
	creditTextTexture = SurfaceToTexture(creditText);

	SDL_QueryTexture(creditTextTexture, NULL, NULL, &creditTextRect.w, &creditTextRect.h);
	creditTextRect.x = 15;
	creditTextRect.y = 225;
	pos[1] = creditTextRect;
}

void CreditMenu::MakeCreditTitle(SDL_Color color){
	SDL_Surface* helpTitle = TTF_RenderText_Blended(titleFont, "Credits", color);
	helpCreditTexture = SurfaceToTexture(helpTitle);

	SDL_QueryTexture(helpCreditTexture, NULL, NULL, &creditTitleRect.w, &creditTitleRect.h);
	creditTitleRect.x = 540 - (creditTitleRect.w / 2);
	creditTitleRect.y = 5;
	pos[2] = creditTitleRect;
}

SDL_Texture* CreditMenu::SurfaceToTexture(SDL_Surface* surf)
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface(renderer, surf);

	SDL_FreeSurface(surf);

	return text;
}

void CreditMenu::SetupRenderer(){

}

void CreditMenu::Draw(){
	SDL_RenderCopy(renderer, backToMainTexture, nullptr, &backToMainRect);
	SDL_RenderCopy(renderer, creditTextTexture, nullptr, &creditTextRect);
	SDL_RenderCopy(renderer, helpCreditTexture, nullptr, &creditTitleRect);
}

void CreditMenu::Update(float dt){

}

void CreditMenu::Highlight(int item){
	switch (item){
	case -1:
	{
		MakeBackToMain(textColor);
		break;
	}
	case 0:
	{
		MakeBackToMain(hoverTextColor);
		break;
	}
	}
}

void CreditMenu::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events)
{
	//std::cout << "Key events not implemented yet";
}

void CreditMenu::HandleMouseEvents(SDL_Event mainEvent)
{
	switch (mainEvent.type)
	{
	case SDL_QUIT:
		exit(0);
		break;
		case SDL_MOUSEMOTION:
		{hoverX = mainEvent.motion.x;
		hoverY = mainEvent.motion.y;
		for (int ii = 0; ii < 3; ii++)
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
		for (int i = 0; i < 3; i++)
		{
			if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h){
				switch (i){
				case 0:
					//back to main
					SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
					if (mainMenu != nullptr){
						mainMenu->updateMenu(MenuEnum::Previous);
					}
					else {
						pauseMenu->updateMenu(MenuEnum::Previous);
					}
					break;
				}
			}
		}
	}
}


CreditMenu::~CreditMenu()
{
}

