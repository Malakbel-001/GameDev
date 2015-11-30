#include "Player.h"
#include "ShotGun.h"
Player::Player() {
	numFootContacts = 0;
	currentWep = nullptr;
	currentwep = 0;
	weps = vector<Weapon*>();

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
void Player::AddWeapon(Weapon* wep){
	wep->SetShouldDraw(false);
	weps.push_back(wep);
	
}
Weapon* Player::GetCurrentWeapon(){
	weps.at(currentwep)->SetShouldDraw(true);
	return weps.at(currentwep);
}
void Player::SwitchWeapon(int x){
	if ((x < weps.size())){
		weps.at(currentwep)->SetShouldDraw(false);
		currentwep = x;

	}

}

b2Body* Player::GetBody()
{
	return body;
}
