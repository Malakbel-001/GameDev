#pragma once

class Camera
{
	private:
		
		double camWidth;
		double camHeight;

		double lvlWidth;
		double lvlHeight;

		b2Vec2* vec;

	public:
		Camera(double _width, double _height);
		double GetX();
		double GetY();
		double GetWidth();
		double GetHeight();
		void Init(b2Body* vec, double _levelwidth,double _levelheight);
		b2Vec2* GetB2Vec();

		void SetX(double _x);
		void SetY(double _y);

		
		virtual ~Camera();
};
