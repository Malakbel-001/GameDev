#include "LoadState.h"

LoadState::~LoadState() {
	this->Cleanup();
}

void LoadState::Init(GameStateManager* gsm) {
	this->gsm;
	
	
}

void LoadState::Cleanup() {

}

void LoadState::Pause() {

}

void LoadState::Resume() {

}

void LoadState::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events) {
	for (auto it = _events->begin(); it != _events->end(); ++it){
		if (it->second)	{
			switch (it->first) {
			case SDLK_SPACE:
				//do something
				break;
			default:
				//do nothing
				break;
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

}