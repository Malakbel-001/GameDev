#include "OptionMenu.h"
#include "MenuState.h"
#include "PauseState.h"
OptionMenu::OptionMenu(MenuState* menu, SDL_Renderer* renderer, TTF_Font* textfont, TTF_Font* titlefont)
{
	settingsConfig = SettingsConfig();
	LoadSettings(settingsConfig.LoadSettings());
	textColor = { 255, 255, 255, 255 }; // white;
	hoverTextColor = { 255, 0, 0, 255 }; // red
	this->mainMenu = menu;
	this->renderer = renderer;
	this->textFont = textfont;
	this->titleFont = titlefont;
	MakeBackToMain(textColor);
	MakeSfxOn(textColor);
	MakeSfxOff(textColor);
	MakeMusicOn(textColor);
	MakeMusicOff(textColor);
	MakeFullScreenOn(textColor);
	MakeFullScreenOff(textColor);
	MakeOptionTitle(textColor);
}

OptionMenu::OptionMenu(PauseState* menu, SDL_Renderer* renderer, TTF_Font* textfont, TTF_Font* titlefont)
{
	settingsConfig = SettingsConfig();
	LoadSettings(settingsConfig.LoadSettings());
	mainMenu = nullptr;
	textColor = { 255, 255, 255, 255 }; // white;
	hoverTextColor = { 255, 0, 0, 255 }; // red
	this->pauseMenu = menu;
	this->renderer = renderer;
	this->textFont = textfont;
	this->titleFont = titlefont;
	MakeBackToMain(textColor);
	MakeSfxOn(textColor);
	MakeSfxOff(textColor);
	MakeMusicOn(textColor);
	MakeMusicOff(textColor);
	MakeFullScreenOn(textColor);
	MakeFullScreenOff(textColor);
	MakeOptionTitle(textColor);
}

void OptionMenu::Init(){

}

void OptionMenu::MakeBackToMain(SDL_Color color){
	SDL_Surface* backToMain = TTF_RenderText_Blended(textFont, "Back", color);
	backToMainTexture = SurfaceToTexture(backToMain);

	SDL_QueryTexture(backToMainTexture, NULL, NULL, &backToMainRect.w, &backToMainRect.h);
	backToMainRect.x = 5;
	backToMainRect.y = 5;
	pos[0] = backToMainRect;
}

void OptionMenu::MakeSfxOn(SDL_Color color){
	SDL_Surface* sfxOnButton = TTF_RenderText_Blended(textFont, "Sound effects - On", color);
	sfxOnTexture = SurfaceToTexture(sfxOnButton);

	SDL_QueryTexture(sfxOnTexture, NULL, NULL, &sfxOnRect.w, &sfxOnRect.h);
	sfxOnRect.x = 15;
	sfxOnRect.y = 225;
	pos[1] = sfxOnRect;
}
void OptionMenu::MakeSfxOff(SDL_Color color){
	SDL_Surface* sfxOffButton = TTF_RenderText_Blended(textFont, "Sound effects - Off", color);
	sfxOffTexture = SurfaceToTexture(sfxOffButton);

	SDL_QueryTexture(sfxOffTexture, NULL, NULL, &sfxOffRect.w, &sfxOffRect.h);
	sfxOffRect.x = 15;
	sfxOffRect.y = 225;
	pos[2] = sfxOffRect;
}
void OptionMenu::MakeMusicOn(SDL_Color color){
	SDL_Surface* musicOnButton = TTF_RenderText_Blended(textFont, "Music - On", color);
	musicOnTexture = SurfaceToTexture(musicOnButton);

	SDL_QueryTexture(musicOnTexture, NULL, NULL, &musicOnRect.w, &musicOnRect.h);
	musicOnRect.x = 15;
	musicOnRect.y = sfxOnRect.y + sfxOnRect.h + 20;
	pos[3] = musicOnRect;
}
void OptionMenu::MakeMusicOff(SDL_Color color){
	SDL_Surface* musicOffButton = TTF_RenderText_Blended(textFont, "Music - Off", color);
	musicOffTexture = SurfaceToTexture(musicOffButton);

	SDL_QueryTexture(musicOffTexture, NULL, NULL, &musicOffRect.w, &musicOffRect.h);
	musicOffRect.x = 15;
	musicOffRect.y = sfxOnRect.y + sfxOnRect.h + 20;
	pos[4] = musicOffRect;
}
void OptionMenu::MakeFullScreenOn(SDL_Color color){
	SDL_Surface* fullScreenOnButton = TTF_RenderText_Blended(textFont, "Fullscreen-On", color);
	fullScreenOnTexture = SurfaceToTexture(fullScreenOnButton);

	SDL_QueryTexture(fullScreenOnTexture, NULL, NULL, &fullScreenOnRect.w, &fullScreenOnRect.h);
	fullScreenOnRect.x = 15;
	fullScreenOnRect.y = musicOnRect.y + musicOnRect.h + 20;
	pos[5] = fullScreenOnRect;
}
void OptionMenu::MakeFullScreenOff(SDL_Color color){
	SDL_Surface* fullScreenOffButton = TTF_RenderText_Blended(textFont, "Fullscreen-Off", color);
	fullScreenOffTexture = SurfaceToTexture(fullScreenOffButton);

	SDL_QueryTexture(fullScreenOffTexture, NULL, NULL, &fullScreenOffRect.w, &fullScreenOffRect.h);
	fullScreenOffRect.x = 15;
	fullScreenOffRect.y = musicOnRect.y + musicOnRect.h + 20;
	pos[6] = fullScreenOffRect;
}
void OptionMenu::MakeOptionTitle(SDL_Color color){
	SDL_Surface* optionsTitle = TTF_RenderText_Blended(titleFont, "Options", color);
	optionsTitleTexture = SurfaceToTexture(optionsTitle);

	SDL_QueryTexture(optionsTitleTexture, NULL, NULL, &optionsTitleRect.w, &optionsTitleRect.h);
	optionsTitleRect.x = 540 - (optionsTitleRect.w / 2);
	optionsTitleRect.y = 5;
	pos[7] = optionsTitleRect;
}

SDL_Texture* OptionMenu::SurfaceToTexture(SDL_Surface* surf)
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface(renderer, surf);

	SDL_FreeSurface(surf);

	return text;
}

void OptionMenu::SetupRenderer(){

}

void OptionMenu::LoadSettings(map<string, bool> settingsMap) {
	if (SoundBank::GetInstance()->IsEnabledMusic() != settingsMap["music"]) {
		SoundBank::GetInstance()->ToggleMusic(SoundBgmType::TESTBGM1);
	}
	if (SoundBank::GetInstance()->IsEnabledSFX() != settingsMap["sfx"]) {
		SoundBank::GetInstance()->ToggleSFX();
	}
	if (settingsMap["fullscreen"]) {
		SDL_SetWindowFullscreen(SDL_GetWindowFromID(1), SDL_WINDOW_FULLSCREEN_DESKTOP);
	}
}
void OptionMenu::Draw(){
	SDL_RenderCopy(renderer, optionsTitleTexture, nullptr, &optionsTitleRect);
	if (SoundBank::GetInstance()->IsEnabledMusic()) { //BGM
		SDL_RenderCopy(renderer, musicOnTexture, nullptr, &musicOnRect);
	}
	else { //BGM
		SDL_RenderCopy(renderer, musicOffTexture, nullptr, &musicOffRect);
	}
	if (SoundBank::GetInstance()->IsEnabledSFX()) { //SFX
		SDL_RenderCopy(renderer, sfxOnTexture, nullptr, &sfxOnRect);
	}
	else { //SFX
		SDL_RenderCopy(renderer, sfxOffTexture, nullptr, &sfxOffRect);
	}
	SDL_Window* window = SDL_GetWindowFromID(1); //works as long as we have only 1 window
	Uint32 flags = SDL_GetWindowFlags(window); //sdl window flags including fullscreen desktop flag
	if ((flags & SDL_WINDOW_FULLSCREEN_DESKTOP) == SDL_WINDOW_FULLSCREEN_DESKTOP) {
		SDL_RenderCopy(renderer, fullScreenOnTexture, nullptr, &fullScreenOnRect);
	}
	else {
		SDL_RenderCopy(renderer, fullScreenOffTexture, nullptr, &fullScreenOffRect);
	}

	SDL_RenderCopy(renderer, backToMainTexture, nullptr, &backToMainRect);
}

void OptionMenu::Update(float dt){

}

void OptionMenu::Highlight(int item){
	switch (item){
	case -1:
	{
		MakeBackToMain(textColor);
		MakeSfxOn(textColor);
		MakeSfxOff(textColor);
		MakeMusicOn(textColor);
		MakeMusicOff(textColor);
		MakeFullScreenOn(textColor);
		MakeFullScreenOff(textColor);
		break;
	}
	case 0:
	{
		MakeBackToMain(hoverTextColor);
		break;
	}
	case 1:
	{
		MakeSfxOn(hoverTextColor);
		MakeSfxOff(hoverTextColor);
		break;
	}
	case 2:
	{
		MakeSfxOff(hoverTextColor);
		MakeSfxOn(hoverTextColor);
		break;
	}
	case 3:
	{
		MakeMusicOn(hoverTextColor);
		MakeMusicOff(hoverTextColor);
		break;
	}
	case 4:
	{
		MakeMusicOff(hoverTextColor);
		MakeMusicOn(hoverTextColor);
		break;
	}
	case 5:
	{
		MakeFullScreenOn(hoverTextColor);
		MakeFullScreenOff(hoverTextColor);
		break;
	}
	case 6:
	{
		MakeFullScreenOff(hoverTextColor);
		MakeFullScreenOn(hoverTextColor);
		break;
	}
	case 7:
	{
		MakeFullScreenOn(hoverTextColor);
		MakeFullScreenOff(hoverTextColor);
		break;
	}
	}
}

void OptionMenu::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events)
{
	//std::cout << "Key events not implemented yet";
}

void OptionMenu::HandleMouseEvents(SDL_Event mainEvent)
{
	switch (mainEvent.type)
	{
	case SDL_QUIT:
		exit(0);
		break;
		case SDL_MOUSEMOTION:
		{hoverX = mainEvent.motion.x;
		hoverY = mainEvent.motion.y;
		for (int ii = 0; ii < 8; ii++)
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
					SoundBank::GetInstance()->Play(SoundEffectType::CORRECT);
					if (mainMenu != nullptr){
						mainMenu->updateMenu(MenuEnum::Previous);
					}
					else {
						pauseMenu->updateMenu(MenuEnum::Previous);
					}
					break;
				case 1:
					//SFX
					SoundBank::GetInstance()->ToggleSFX();
						SoundBank::GetInstance()->Play(SoundEffectType::CORRECT);
						settingsConfig.SaveSettings(SoundBank::GetInstance()->IsEnabledMusic(),
							SoundBank::GetInstance()->IsEnabledSFX(),
							(flags & SDL_WINDOW_FULLSCREEN_DESKTOP) == SDL_WINDOW_FULLSCREEN_DESKTOP);
					break;
				case 3:
					//music
					SoundBank::GetInstance()->ToggleMusic(SoundBgmType::TESTBGM1);
						SoundBank::GetInstance()->Play(SoundEffectType::CORRECT);
						settingsConfig.SaveSettings(SoundBank::GetInstance()->IsEnabledMusic(),
							SoundBank::GetInstance()->IsEnabledSFX(),
							(flags & SDL_WINDOW_FULLSCREEN_DESKTOP) == SDL_WINDOW_FULLSCREEN_DESKTOP);
					break;
				case 5:
					//fullscreen
						SDL_Window* window = SDL_GetWindowFromID(1); //works as long as we have only 1 window
						Uint32 flags = SDL_GetWindowFlags(window); //sdl window flags including fullscreen desktop flag
						if ((flags & SDL_WINDOW_FULLSCREEN_DESKTOP) == SDL_WINDOW_FULLSCREEN_DESKTOP) {
							SDL_SetWindowFullscreen(window, 0); //back to windowed
						}
						else {
							SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
						}
						settingsConfig.SaveSettings(SoundBank::GetInstance()->IsEnabledMusic(),
							SoundBank::GetInstance()->IsEnabledSFX(),
							(flags & SDL_WINDOW_FULLSCREEN_DESKTOP) != SDL_WINDOW_FULLSCREEN_DESKTOP);
						SoundBank::GetInstance()->Play(SoundEffectType::CORRECT);
						break;
				}
			}
		}
	}
}


OptionMenu::~OptionMenu()
{
}
