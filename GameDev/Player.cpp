#include "Player.h"

#include "ShotGun.h"
#include "Weapon.h"
Player::Player() {
	

}

Player::~Player() { }

Actor* Player::EmptyClone()
{
	return new Player();
}
void Player::setBody(b2Body* _body)
{
	body = _body;

}

b2Body* Player::GetBody()
{
	return body;
}

Weapon* Player::GetCurrentWeapon(){
	if (!currentWep){
		currentWep = new ShotGun(this);
	}		
	return currentWep;
	
}