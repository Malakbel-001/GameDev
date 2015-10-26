#pragma once
class Camera
{
	private:
		double x;
		double y;
		double width;
		double height;
		double mapWidth;
		double mapHeight;
	public:
		Camera(double x, double y, double width, double height, double mapWidth, double mapHeight);
		double GetX();
		double GetY();
		double GetWidth();
		double GetHeight();

		void SetX(double x);
		void SetY(double y);

		virtual ~Camera();
};

