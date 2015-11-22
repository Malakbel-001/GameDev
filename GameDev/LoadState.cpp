#include "LoadState.h"

LoadState::~LoadState() {
	this->Cleanup();
}

void LoadState::Init(GameStateManager* gsm) {
	this->gsm;
	
	//std::thread loadingThread(Test);
	//loadingThread.detach();

	BehaviourFactory* bf = gsm->GetBehaviour();
	drawableContainer = new DrawableContainer();
	DrawableBehaviour* cheatLoad = bf->CreateDrawableBehaviour(EntityType::CHEATLOAD);
	cheatLoad->LoadMedia();
	drawableContainer->Add(cheatLoad);
}

void LoadState::LoadPlayState(GameStateManager* gsm) {
	playState = gsm->GetNewState(GameStateType::PlayState);
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
					gsm->PushGameState(playState);
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
	//draw done with loading press key
}

void LoadState::Draw() {
	drawableContainer->Draw();
}