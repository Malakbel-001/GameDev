#include "MenuState.h"


MenuState::MenuState()
{
}


MenuState::~MenuState()
{
}
void MenuState::Init(GameStateManager *gsm){
	this->gsm = gsm;
}
void MenuState::Cleanup(){

}

void MenuState::Pause(){

}
void MenuState::Resume(){

}

void MenuState::HandleEvents(std::unordered_map<SDL_Keycode, bool>* _events){

}
void MenuState::Update(float dt){

}
void MenuState::Draw(){

}