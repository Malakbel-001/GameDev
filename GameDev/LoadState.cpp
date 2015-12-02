#include "LoadState.h"

//bool		LoadState::loadedPlay = false;
//IGameState* LoadState::playState = NULL;
LoadState::LoadState(){
	loadedPlay = false;
}

LoadState::~LoadState() {
	this->Cleanup();
}

void LoadState::Init(GameStateManager* gsm) {
	this->gsm = gsm;
	this->renderer = gsm->GetBehaviour()->GetRenderer();

	//Create and load Thread, see also the LoadPlayState method
	std::thread loadingThread(&LoadState::LoadPlayState,this);
	loadingThread.detach();

	SDL_SetRenderDrawColor(gsm->GetBehaviour()->GetRenderer(), 0, 0, 0, 255);

	//Icon loading, temporary, will use sprite class after this instead of this cheatDrawBehaviour + cheatDrawContainer
	BehaviourFactory* bf = gsm->GetBehaviour();
	drawableContainer = new DrawableContainer();
	bare = new BareEntity();
	bare->Init(0, 0, 0, EntityState::WALKINGRIGHT, EntityType::PLAYER, bf, drawableContainer);

	
	//cheatLoad->LoadMedia();
//	drawableContainer->Add(cheatLoad);

	//Textures / Display Text Loading... and Press any key to Continue
	TTF_Init(); //Init Font
	textFont = TTF_OpenFont("armalite_rifle.ttf", 23);
	if (textFont == nullptr) {
		std::cout << " Failed to load font : " << TTF_GetError() << std::endl; //just in case...
	}

	//Sorry for wall of code

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
	//Fyi: Error handling, compared to menuState methods @InitializationEverything, here is baddy bad bad, at least for now unless not needed.

	//Advertisement placeholder
	Advertisement("Resources/images/ad.png");

	background.loadFromFile(gsm->GetBehaviour()->GetRenderer(), "Resources/backgrounds/loadscreen.png");
	backgroundRect.h = background.getHeight();
	backgroundRect.w = background.getWidth();
	backgroundRect.x = 0;
	backgroundRect.y = 0;
}

void LoadState::LoadPlayState() {
 	playState = gsm->GetNewState(GameStateType::PlayState);
	playState->Init(gsm);
	loadedPlay = true;
}

//path = path of the advertisement image
void LoadState::Advertisement(char* path) {
	advertisementPic = LTexture();
	advertisementPic.loadFromFile(renderer, path);
	advertisementRect.h = advertisementPic.getHeight();
	advertisementRect.w = advertisementPic.getWidth();
	advertisementRect.x = 0;
	advertisementRect.y = 0;
}

void LoadState::Cleanup() {
	TTF_CloseFont(textFont);

	delete drawableContainer;
	drawableContainer = nullptr;

	delete bare;
	//Bugged. Uhhm? Maybe SDL deletes those pointers himself anyway?
	/*delete loadingTexture;
	delete finishedTexture;*/

	/*loadingTexture = nullptr;
	finishedTexture = nullptr;*/
}

void LoadState::Pause() {
	std::cout << "Not implemented Pause" << std::endl;
}

void LoadState::Resume() {
	std::cout << "Not implemented Resume" << std::endl;
}

void LoadState::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events) {
	if (loadedPlay) {
		for (auto it = _events->begin(); it != _events->end(); ++it){
			if (it->second)	{
				switch (it->first) {
					default: //don't know how to remove warning except for creating an empty case
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
	//temp bg
	//background.render(gsm->GetBehaviour()->GetRenderer(), 0, 0, 0, &backgroundRect); //TEMP!

	drawableContainer->Draw();

	if (!loadedPlay) {	//Loading...
		SDL_RenderCopy(renderer, loadingTexture, nullptr, &loadingRect);
	}
	else {				//Press any key to continue
		SDL_RenderCopy(renderer, finishedTexture, nullptr, &finishedRect);
	}

	advertisementPic.render(renderer, 50, loadingRect.y + loadingRect.h + 50, 0,&advertisementRect);
}