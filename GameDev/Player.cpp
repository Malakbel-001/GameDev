#include "Player.h"

#include <iostream>
Player::Player()
{
	
}

Entity* Player::EmptyClone()
{
	std::cout << "player";
	return new Player();
}
void Player::setBody(b2Body* _body){
	body = _body;

}

Player::~Player()
{
}