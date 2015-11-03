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

void MenuState::HandleEvents(SDL_Event mainEvent){

}
void MenuState::Update(float dt){

}
void MenuState::Draw(SDL_Renderer*  sdl){

}