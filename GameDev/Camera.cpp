#include "Camera.h"

Camera::Camera(double x, double y, double width, double height, double mapWidth, double mapHeight)
	: x(x), y(y), width(width), height(height), mapWidth(mapWidth), mapHeight(mapHeight)
{ }

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
	return width;
}

double Camera::GetHeight()
{
	return height;
}

void Camera::SetX(double x)
{
	if (x + this->GetWidth() < this->mapWidth && x > 0)
	{
		this->x = x;
	}
}

void Camera::SetY(double y)
{
	if (y + this->GetHeight() < this->mapHeight && y > 0)
	{
		this->y = y;
	}
}

Camera::~Camera()
{ }
