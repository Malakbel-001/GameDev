#include "Camera.h"
#include "Player.h"

Camera::Camera(double _camWidth, double _camHeight) :
	 camWidth(_camWidth), camHeight(_camHeight)
{ 
	player = nullptr;
}

Camera::~Camera() { }


double Camera::GetWidth()
{
	return lvlWidth;
}

double Camera::GetHeight()
{
	return lvlHeight;
}
double Camera::GetX(){
	if (player){
		return player->GetBody()->GetPosition().x;
	}
	else{
		return camX;
	}
}
double Camera::GetY(){
	if (player){
		return player->GetBody()->GetPosition().y;
	}
	else{
		return camY;
	}
}

//camera locked on the player
void Camera::Init(Player* _player, double _levelwidth, double _levelheight){
	lvlWidth = _levelwidth;
	lvlHeight = _levelheight;
	player = _player;
}
void Camera::Init(double _levelwidth, double _levelheight) {
	lvlWidth = _levelwidth;
	lvlHeight = _levelheight;
}

Player* Camera::GetPlayer()
{
	return player;
}

void Camera::SetPlayer(Player* _player)
{
	player = _player;
}

void Camera::SetX(double _x) {
	camX = _x;
}

void Camera::SetY(double _y) {
	camY = _y;
}
