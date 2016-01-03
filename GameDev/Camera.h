#pragma once
#include <Box2D\Box2D.h>

class Player;
class Camera
{
	private:
		
		double camWidth;
		double camHeight;

		double lvlWidth;
		double lvlHeight;

		double camX = 0;
		double camY = 0;

		Player* player;

	public:
		Camera(double _width, double _height);
		double GetX();
		double GetY();
		double GetWidth();
		double GetHeight();
		void Init(Player* _player, double _levelwidth, double _levelheight);
		void Init(double _levelwidth, double _levelheight);

		b2Body* GetB2Body();

		void SetX(double _x);
		void SetY(double _y);

		
		virtual ~Camera();
};
