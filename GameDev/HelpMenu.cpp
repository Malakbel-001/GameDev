#include "HelpMenu.h"
#include "MenuState.h"
#include "PauseState.h"
HelpMenu::HelpMenu(MenuState* menu, SDL_Renderer* renderer, TTF_Font* textfont, TTF_Font* titlefont)
{
	textColor = { 255, 255, 255, 255 }; // white;
	hoverTextColor = { 255, 0, 0, 255 }; // red
	this->mainMenu = menu;
	this->renderer = renderer;
	this->textFont = textfont;
	this->titleFont = titlefont;
	MakeBackToMain(textColor);
	MakeHelpText(textColor);
	MakeHelpTitle(textColor);
}

HelpMenu::HelpMenu(PauseState* menu, SDL_Renderer* renderer, TTF_Font* textfont, TTF_Font* titlefont)
{
	mainMenu = nullptr;
	textColor = { 255, 255, 255, 255 }; // white;
	hoverTextColor = { 255, 0, 0, 255 }; // red
	this->pauseMenu = menu;
	this->renderer = renderer;
	this->textFont = textfont;
	this->titleFont = titlefont; 
	MakeBackToMain(textColor);
	MakeHelpText(textColor);
	MakeHelpTitle(textColor);
}

void HelpMenu::Init(){

}

void HelpMenu::MakeBackToMain(SDL_Color color){
	SDL_Surface* backToMain = TTF_RenderText_Blended(textFont, "Back", color);
	backToMainTexture = SurfaceToTexture(backToMain);

	SDL_QueryTexture(backToMainTexture, NULL, NULL, &backToMainRect.w, &backToMainRect.h);
	backToMainRect.x = 5;
	backToMainRect.y = 5;
	pos[0] = backToMainRect;
}

void HelpMenu::MakeHelpText(SDL_Color color){
	SDL_Surface* helpText = TTF_RenderText_Blended_Wrapped(textFont, "Het Spel bestuur je doormiddel van het toetsenboard. Je gebruik de volgende knoppen om de speler te besturen:\n-W = Springen/Klimmen.\n-A = Naar links lopen.\n-S = Naar beneden klimmen.\n-D = Naar rechts lopen.\n\nNog een tip, probeer vooral op het gras te blijven, anders is de kans op overleven erg klein.", color, 1000);
	helpTextTexture = SurfaceToTexture(helpText);

	SDL_QueryTexture(helpTextTexture, NULL, NULL, &helpTextRect.w, &helpTextRect.h);
	helpTextRect.x = 15;
	helpTextRect.y = 225;
	pos[1] = helpTextRect;
}

void HelpMenu::MakeHelpTitle(SDL_Color color){
	SDL_Surface* helpTitle = TTF_RenderText_Blended(titleFont, "Help", color);
	helpTitleTexture = SurfaceToTexture(helpTitle);

	SDL_QueryTexture(helpTitleTexture, NULL, NULL, &helpTitleRect.w, &helpTitleRect.h);
	helpTitleRect.x = 540 - (helpTitleRect.w / 2);
	helpTitleRect.y = 5;
	pos[2] = helpTitleRect;
}

SDL_Texture* HelpMenu::SurfaceToTexture(SDL_Surface* surf)
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface(renderer, surf);

	SDL_FreeSurface(surf);

	return text;
}

void HelpMenu::SetupRenderer(){

}

void HelpMenu::Draw(){
	SDL_RenderCopy(renderer, backToMainTexture, nullptr, &backToMainRect);
	SDL_RenderCopy(renderer, helpTextTexture, nullptr, &helpTextRect);
	SDL_RenderCopy(renderer, helpTitleTexture, nullptr, &helpTitleRect);
}

void HelpMenu::Update(float dt){

}
void HelpMenu::Highlight(int item){
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


void HelpMenu::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events)
{
	//std::cout << "Key events not implemented yet";
}

void HelpMenu::HandleMouseEvents(SDL_Event mainEvent)
{
	switch (mainEvent.type)
	{

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


HelpMenu::~HelpMenu()
{
}
