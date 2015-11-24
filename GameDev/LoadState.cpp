#include "LoadState.h"

bool		LoadState::loadedPlay = false;
IGameState* LoadState::playState = NULL;

LoadState::~LoadState() {
	this->Cleanup();
}

void LoadState::Init(GameStateManager* gsm) {
	this->gsm = gsm;
	this->renderer = gsm->GetBehaviour()->GetRenderer();
	
	std::thread loadingThread(LoadPlayState, gsm);
	loadingThread.detach();

	//Icon loading, temporary, will use sprite class after this instead of this cheatDrawBehaviour + cheatDrawContainer
	BehaviourFactory* bf = gsm->GetBehaviour();
	drawableContainer = new DrawableContainer();
	DrawableBehaviour* cheatLoad = bf->CreateDrawableBehaviour(EntityType::CHEATLOAD);
	cheatLoad->LoadMedia();
	drawableContainer->Add(cheatLoad);
	//Icon Loading End.

	//Textures / Display Text Loading... and Press any key to Continue
	TTF_Init(); //Init Font
	textFont = TTF_OpenFont("armalite_rifle.ttf", 23);
	if (textFont == nullptr) {
		std::cout << " Failed to load font : " << TTF_GetError() << std::endl; //just in case...
	}

	SDL_Color textColor = { 255, 255, 255, 255 }; // white
	//loadingTexture, based on menuState, trying to keep code short, but maybe we need a text texture utility class?
	SDL_Surface* loadingSurface = TTF_RenderText_Blended(textFont, "Loading...", textColor);
	loadingTexture = SDL_CreateTextureFromSurface(renderer, loadingSurface);
	SDL_FreeSurface(loadingSurface); //not sure why this is needed
	SDL_QueryTexture(loadingTexture, NULL, NULL, &loadingRect.w, &loadingRect.h);
	loadingRect.x = 100;
	loadingRect.y = 20;

	//finishedLoadingTexture, based on menuState, trying to keep code short, but maybe we need a text texture utility class?
	SDL_Surface* finishedSurface = TTF_RenderText_Blended(textFont, "Press any key to continue", textColor);
	finishedTexture = SDL_CreateTextureFromSurface(renderer, finishedSurface);
	SDL_FreeSurface(finishedSurface); //not sure why this is needed
	SDL_QueryTexture(finishedTexture, NULL, NULL, &finishedRect.w, &finishedRect.h);
	finishedRect.x = 100;
	finishedRect.y = 20;
	//Textures End, Fyi: Error handling here is baddy bad bad, at least for now.
}

void LoadState::LoadPlayState(GameStateManager* gsm) {
	playState = gsm->GetNewState(GameStateType::PlayState);
	playState->Init(gsm);
	loadedPlay = true;
}

void LoadState::CreateTextures() {
	
}

void LoadState::Cleanup() {
	delete(playState);
	delete(drawableContainer);
}

void LoadState::Pause() {
	std::cout << "Not implemented Pause" << std::endl;
}

void LoadState::Resume() {
	std::cout << "Not implemented Resume" << std::endl;
}

void LoadState::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events) {
	if (loadedPlay) {
		for (auto it = _events->begin(); it != _events->end(); ++it){ //still needed, or will removing this bring potential bugs?
			if (it->second)	{
				switch (it->first) {
					default:
						gsm->PushGameStateOnly(playState); //any key
						break;
				}
			}
		}
	}
}

void LoadState::HandleMouseEvents(SDL_Event mainEvent) {
	//temp nothing
}

void LoadState::Update(float dt) {
	//nope
}

void LoadState::Draw() {
	drawableContainer->Draw();

	if (!loadedPlay) {
		SDL_RenderCopy(renderer, loadingTexture, nullptr, &loadingRect);
	}
	else {
		SDL_RenderCopy(renderer, finishedTexture, nullptr, &finishedRect);
	}
}