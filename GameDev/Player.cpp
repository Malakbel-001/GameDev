#include "Player.h"
#include "ShotGun.h"
Player::Player() {
	numFootContacts = 0;
	currentWep = nullptr;
	currentwep = 0;
	weps = vector<Weapon*>();
	score = 0;
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
bool Player::ContainsWeapons() {
	return !weps.empty();
}
void Player::SwitchWeapon(int x){
	if ((x < weps.size())){
		weps.at(currentwep)->SetShouldDraw(false);
		currentwep = x;
		weps.at(currentwep)->SetShouldDraw(true);
	}

}
void Player::DeleteWeapons() {
	for (auto weapon : weps) {
		delete(weapon);
		weapon = nullptr;
	}
	weps.clear();
}
b2Body* Player::GetBody()
{
	return body;
}
void Player::AddScore(int _score) {
	score = score + _score;
}
int Player::GetScore() {
	return score;
}