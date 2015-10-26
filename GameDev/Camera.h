#pragma once
#include "Player.h"

class Camera
{
	private:
		double x;
		double y;
		double width;
		double height;
		double mapWidth;
		double mapHeight;
		Player* player;

	protected:
		// Stuff

	public:
		Camera(double x, double y, double width, double height, double mapWidth, double mapHeight, Player* p);
		double GetX();
		double GetY();
		double GetWidth();
		double GetHeight();

		void SetX(double x);
		void SetY(double y);

		virtual ~Camera();
};

