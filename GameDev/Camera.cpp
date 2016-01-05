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

//manual camera unlocked
void Camera::Init(double _levelWidth, double _levelHeight) {
	lvlWidth = _levelWidth;
	lvlHeight = _levelHeight;
}

void Camera::SetX(double _x) {
	camX = _x;
}

void Camera::SetY(double _y) {
	camY = _y;
}