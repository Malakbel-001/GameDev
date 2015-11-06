#include "Camera.h"
#include "Player.h"

Camera::Camera(double _camWidth, double _camHeight) :
	 camWidth(_camWidth), camHeight(_camHeight)
{ }

Camera::~Camera() { }


double Camera::GetWidth()
{
	return lvlWidth;
}

double Camera::GetHeight()
{
	return lvlHeight;
}

void Camera::Init(b2Vec2* _vec, double _levelwidth, double _levelheight){
	lvlWidth = _levelwidth;
	lvlHeight = _levelheight;
	vec = _vec;
}
b2Vec2* Camera::GetB2Vec(){
	return vec;
}





