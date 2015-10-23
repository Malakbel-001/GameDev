#pragma once
#include "Box2D\Box2D.h"
#include "Camera.h"

class Level
{
	private:

	protected:
		int lvlWigth, lvlHeight;
		b2World* world;
		Camera* camera;

	public:
		Level(int _lvlWidth, int _lvlHeight);
		virtual ~Level();

		virtual void setLvlWidth(int _lvlWidth);
		virtual void setLvlHeight(int _lvlHeight);

		virtual int getLvlWidth();
		virtual int getLvlHeight();

		virtual b2World* GetWorld();

};
