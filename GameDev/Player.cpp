#include "Player.h"

Player::Player() {
	

}

Player::~Player() { }

Actor* Player::EmptyClone()
{
	return new Player();
}