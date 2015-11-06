#include "Camera.h"
#include "Player.h"

Camera::Camera(double _camWidth, double _camHeight) :
	 camWidth(_camWidth), camHeight(_camHeight)
{ 


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

	return player->GetBody()->GetPosition().x;
}
double Camera::GetY(){
	return player->GetBody()->GetPosition().y;
}
void Camera::Init(Player* _player, double _levelwidth, double _levelheight){
	lvlWidth = _levelwidth;
	lvlHeight = _levelheight;
	player = _player;
}





