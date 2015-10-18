#include "Player.h"


Player::Player()
{
}
Entity* Player::EmptyClone(){
	return new Player();
}

Player::~Player()
{
}
