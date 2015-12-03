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
		return 0;
	}
}
double Camera::GetY(){
	if (player){
	return player->GetBody()->GetPosition().y;
	}
	else{
		return 0;
	}
}
void Camera::Init(Player* _player, double _levelwidth, double _levelheight){
	lvlWidth = _levelwidth;
	lvlHeight = _levelheight;
	player = _player;
}





