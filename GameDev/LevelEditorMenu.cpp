#include "LevelEditorMenu.h"
#include "MenuState.h"

LevelEditorMenu::LevelEditorMenu(MenuState* menu, SDL_Renderer* renderer, TTF_Font* textfont, TTF_Font* titlefont)
{
	textColor = { 255, 255, 255, 255 }; // white
	hoverTextColor = { 255, 0, 0, 255 }; // red
	this->mainMenu = menu;
	this->renderer = renderer;
	this->textFont = textfont;
	this->titleFont = titlefont;
	MakeBackToMain(textColor);
	MakeEditorTitle(textColor);
	MakeNewLevel(textColor);
	MakeOpen(textColor);
	MakeInput(textColor);
	SDL_StartTextInput();
	lockButtonTicks = SDL_GetTicks();
}

void LevelEditorMenu::Init(){

}

void LevelEditorMenu::MakeBackToMain(SDL_Color color){
	SDL_Surface* backToMain = TTF_RenderText_Blended(textFont, "Back", color);
	backToMainTexture = SurfaceToTexture(backToMain);

	SDL_QueryTexture(backToMainTexture, NULL, NULL, &backToMainRect.w, &backToMainRect.h);
	backToMainRect.x = 5;
	backToMainRect.y = 5;
	pos[0] = backToMainRect;
}

void LevelEditorMenu::MakeNewLevel(SDL_Color color){
	SDL_Surface* newGameButton = TTF_RenderText_Blended(textFont, "New Level. Give a name: ", color);
	newLevelTexture = SurfaceToTexture(newGameButton);

	SDL_QueryTexture(newLevelTexture, NULL, NULL, &newLevelRect.w, &newLevelRect.h);
	newLevelRect.x = 15;
	newLevelRect.y = 225;
	pos[1] = newLevelRect;
}

void LevelEditorMenu::MakeOpen(SDL_Color color){
	SDL_Surface* open = TTF_RenderText_Blended(textFont, "Open...", color);
	openTexture = SurfaceToTexture(open);

	SDL_QueryTexture(openTexture, NULL, NULL, &OpenRect.w, &OpenRect.h);
	OpenRect.x = 15;
	OpenRect.y = newLevelRect.y + newLevelRect.h + 20;;
	pos[2] = OpenRect;
}

void LevelEditorMenu::MakeInput(SDL_Color color){
	SDL_Surface* level2Button = TTF_RenderText_Blended(textFont, text.c_str(), color);
	inputTexture = SurfaceToTexture(level2Button);

	SDL_QueryTexture(inputTexture, NULL, NULL, &inputRect.w, &inputRect.h);
	inputRect.x = newLevelRect.x + newLevelRect.w + 5;
	inputRect.y = newLevelRect.y;
	pos[3] = inputRect;
}

void LevelEditorMenu::MakeEditorTitle(SDL_Color color){
	SDL_Surface* editorTitle = TTF_RenderText_Blended(titleFont, "Level Editor", color);
	editorTitleTexture = SurfaceToTexture(editorTitle);

	SDL_QueryTexture(editorTitleTexture, NULL, NULL, &editorTitleRect.w, &editorTitleRect.h);
	editorTitleRect.x = 540 - (editorTitleRect.w / 2);
	editorTitleRect.y = 5;
	pos[4] = editorTitleRect;
}

SDL_Texture* LevelEditorMenu::SurfaceToTexture(SDL_Surface* surf)
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface(renderer, surf);

	SDL_FreeSurface(surf);

	return text;
}

void LevelEditorMenu::SetupRenderer(){

}

void LevelEditorMenu::Draw(){
	SDL_RenderCopy(renderer, editorTitleTexture, nullptr, &editorTitleRect);
	SDL_RenderCopy(renderer, newLevelTexture, nullptr, &newLevelRect);
	SDL_RenderCopy(renderer, openTexture, nullptr, &OpenRect);
	SDL_RenderCopy(renderer, inputTexture, nullptr, &inputRect);
	SDL_RenderCopy(renderer, backToMainTexture, nullptr, &backToMainRect);
}

void LevelEditorMenu::Update(float dt){

}

void LevelEditorMenu::Highlight(int item){
	switch (item){
	case -1:
	{
		MakeBackToMain(textColor);
		MakeEditorTitle(textColor);
		MakeNewLevel(textColor);
		MakeOpen(textColor);
		MakeInput(textColor);
		break;
	}
	case 0:
	{
		MakeBackToMain(hoverTextColor);
		break;
	}
	case 1:
	{
		MakeNewLevel(hoverTextColor);
		break;
	}
	case 2:
	{
		MakeOpen(hoverTextColor);
		break;
	}
	}
}

void LevelEditorMenu::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events)
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
						MakeInput(textColor);

						lockButtonTicks = SDL_GetTicks();
					}
				}
				break;
			}
		}
	}
}

void LevelEditorMenu::HandleTextInputEvents(SDL_Event event){
	switch (event.type){
	case SDL_TEXTINPUT:
		if (/*event.type == SDL_KEYDOWN && */event.key.keysym.sym == SDLK_BACKSPACE && text.length() > 0){
			text = text.substr(0, text.length() - 1);
		}
		else if (SDL_TEXTINPUT){
			text += event.text.text;
		}
		MakeInput(textColor);
		break;
	}
}

void LevelEditorMenu::HandleMouseEvents(SDL_Event mainEvent)
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
					SDL_StopTextInput();
					mainMenu->updateMenu(MenuEnum::Previous);
					break;
				case 1:
					//new level
						SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
						if (text != ""){
							mainMenu->GetGSM()->CreateGameState(GameStateType::EditorState);
							static_cast<EditorState*>(mainMenu->GetGSM()->GetCurrentState())->SetName(text);
						}
						else {
							cout << "no name provided.";
						}
						//mainMenu->GetGSM()->CreateGameState(GameStateType::LoadState, 1);
					break;
				case 2:
					//open
						SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
						OPENFILENAMEA ofn = { 0 };
						char Buffer[300];
						fill(Buffer, Buffer + 300, '\0');
						ofn.lStructSize = sizeof(OPENFILENAMEA);
						//ofn.hwndOwner = hWnd;
						ofn.lpstrFile = Buffer;
						ofn.nMaxFile = 300;
						ofn.Flags = OFN_EXPLORER | OFN_NOCHANGEDIR;
						ofn.lpstrFilter = NULL;
						ofn.lpstrCustomFilter = NULL;
						ofn.nFilterIndex = 0;
						ofn.lpstrFileTitle = NULL;
						ofn.lpstrInitialDir = NULL;
						ofn.lpstrTitle = NULL;
						if (GetOpenFileName){
							cout << GetOpenFileNameA(&ofn) << endl;
							cout << Buffer << endl;
							if (Buffer[1] != '\0'){
								mainMenu->GetGSM()->CreateGameState(GameStateType::EditorState, Buffer);
							}
							else {
								cout << "No file selected.";
							}
						}
						else{
							cout << "clicked cancel";
						}
					break;
				}
			}
		}
	}
}


LevelEditorMenu::~LevelEditorMenu()
{
}
