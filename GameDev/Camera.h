#pragma once

class Player;

class Camera
{
	private:
		double x;
		double y;
		double camWidth;
		double camHeight;
		double lvlWidth;
		double lvlHeight;

	public:
		Camera(double _x, double _y, double _width, double _height, double _lvlWidth, double _lvlHeight);
		double GetX();
		double GetY();
		double GetWidth();
		double GetHeight();

		void SetX(double _x);
		void SetY(double _y);

		void UpdateCamaraPosition(double eX, double eY, double eWidth, double eHeight);

		virtual ~Camera();
};
