#include "IGameState.h"

GameStateManager* IGameState::GetGSM(){
	return gsm;
}

IGameState::~IGameState()
{ }