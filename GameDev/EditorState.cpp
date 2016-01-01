#include "EditorState.h"

EditorState::EditorState() {

}

EditorState::~EditorState() {

}

void EditorState::Cleanup() {

}

void EditorState::Init(GameStateManager *gsm){

}

void EditorState::Pause() {
	//does nothing atm
}

void EditorState::Resume() {
	//nothing to resume yet
}

void EditorState::HandleMouseEvents(SDL_Event mainEvent) {
	//follow mouse movements, show level entity
}

void EditorState::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events) {
	//camera

	//scroll entity stuff
}

void EditorState::HandleTextInputEvents(SDL_Event event) {
	//new stuff hmm
}

void EditorState::Update(float dt) {
	//don't know what to update
}

void EditorState::Draw() {
	//display current level
}