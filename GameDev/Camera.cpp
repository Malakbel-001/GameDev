#include "Camera.h"
#include "Player.h"

Camera::Camera(double _x, double _y, double _camWidth, double _camHeight, double _lvlWidth, double _lvlHeight) :
	x(_x), y(_y), camWidth(_camWidth), camHeight(_camHeight), lvlWidth(_lvlWidth), lvlHeight(_lvlHeight)
{ }

Camera::~Camera() { }

double Camera::GetX()
{
	return x;
}

double Camera::GetY()
{
	return y;
}

double Camera::GetWidth()
{
	return lvlWidth;
}

double Camera::GetHeight()
{
	return lvlHeight;
}

void Camera::SetX(double x)
{
	//if (x + this->GetWidth() < this->lvlWidth && x > 0)
		this->x = x;
}

void Camera::SetY(double y)
{
	//if (y + this->GetHeight() < this->lvlHeight && y > 0)
		this->y = y;
}

void Camera::UpdateCamaraPosition(double eX, double eY, double eWidth, double eHeight)
{
	this->SetX((eX + eWidth / 2) - (this->lvlWidth / 2));
	this->SetY((eY + eHeight / 2) - (this->lvlHeight / 2));
}
