#include "Player.h"
#include "Level.h"
#include "ShotGun.h"
Player::Player() {
	numFootContacts = 0;
	currentWep = nullptr;
	currentwep = 0;
	weps = vector<Weapon*>();
	score = 0;
	vehicle = nullptr;
	passenger = nullptr;
	timeplayed.resize(2);
	timeplayed.at(0) = 0;
	timeplayed.at(1) = 0;
}

Player::~Player() { 
	DeletePrevProp();
	if (col){
		delete col;
		col = nullptr;
	}
}

void Player::GodMode(bool cheat){
	godmode = cheat;
}

void Player::SetHealth(int _health){
	if (!godmode){
		if (_health <= 0){
			dead = true;
			health = _health;
		}
		else if (_health > maxHealth) {
			health = maxHealth;
		}
		else{
			health = _health;
		}
	}
}

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
	if (weps.at(currentwep))
	{
		weps.at(currentwep)->SetShouldDraw(true);
		return weps.at(currentwep);
	}
	return nullptr;
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

vector<Weapon*> Player::GetWeapons()
{
	return weps;
}

void Player::DeletePrevProp() {
	for (auto weapon : weps) {
		delete weapon;
		weapon = nullptr;
	}
	weps.clear();
}
b2Body* Player::GetBody()
{
	return body;
}
void Player::AddScore(int _score) {
	if (passenger)
		passenger->AddScore(_score);

	score = score + _score;
}
int Player::GetScore() {
	return score;
}

void Player::SetPassenger(Player* _passenger)
{
	passenger = _passenger;
}

void Player::SetVehicle(Player* _vehicle)
{
	vehicle = _vehicle;
}

Player* Player::GetVehicle()
{
	return vehicle;
}

void Player::AddPlayTime(Uint32 timeMin, Uint32 timeSec){
	timeplayed.at(0) += timeMin;
	if (timeplayed.at(1) + timeSec > 60){
		timeplayed.at(0) += 1;
		timeplayed.at(1) = (timeplayed.at(1) + timeSec)-60;
	}
	else {
		timeplayed.at(1) += timeSec;
	}
}

vector<Uint32> Player::GetPlayTime(){
	return timeplayed;
}

bool Player::IsVehicle() {
	if (passenger)
		return true;
	return false;
}