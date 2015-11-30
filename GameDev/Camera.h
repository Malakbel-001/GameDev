#pragma once
#include <Box2D\Box2D.h>
#include "Player.h"

class Camera
{
	private:
		
		double camWidth;
		double camHeight;

		double lvlWidth;
		double lvlHeight;

		Player* player;

	public:
		Camera(double _width, double _height);
		double GetX();
		double GetY();
		double GetWidth();
		double GetHeight();
		void Init(Player* _player, double _levelwidth,double _levelheight);
		b2Body* GetB2Body();

		void SetX(double _x);
		void SetY(double _y);

		
		virtual ~Camera();
};
