#include "LoadState.h"

bool		LoadState::loadedPlay = false;
IGameState* LoadState::playState = NULL;

LoadState::~LoadState() {
	this->Cleanup();
}

void LoadState::Init(GameStateManager* gsm) {
	this->gsm = gsm;
	
	std::thread loadingThread(LoadPlayState, gsm);
	loadingThread.detach();

	BehaviourFactory* bf = gsm->GetBehaviour();
	drawableContainer = new DrawableContainer();
	DrawableBehaviour* cheatLoad = bf->CreateDrawableBehaviour(EntityType::CHEATLOAD);
	cheatLoad->LoadMedia();
	drawableContainer->Add(cheatLoad);
}

void LoadState::LoadPlayState(GameStateManager* gsm) {
	playState = gsm->GetNewState(GameStateType::PlayState);
	playState->Init(gsm);
	loadedPlay = true;
}

void LoadState::Cleanup() {
	delete(playState);
	delete(drawableContainer);
}

void LoadState::Pause() {

}

void LoadState::Resume() {

}

void LoadState::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events) {
	if (loadedPlay) {
		for (auto it = _events->begin(); it != _events->end(); ++it){
			if (it->second)	{
				switch (it->first) {
				case SDLK_SPACE:
					gsm->PushGameStateOnly(playState);
					break;
				default:
					//do something?
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

}

void LoadState::Draw() {
	drawableContainer->Draw();
}