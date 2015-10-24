#pragma once
#include "Box2D\Box2D.h"
#include "Camera.h"

class Level
{
	private:
		int tileWitdh, tileHeight;

	protected:
		int lvlWigth, lvlHeight, lvlTotalTiles;
		b2World* world;
		Camera* camera;
		int LevelTiles;

	public:
		Level(int _lvlWidth, int _lvlHeight);
		virtual ~Level();

		virtual void setLvlWidth(int _lvlWidth);
		virtual void setLvlHeight(int _lvlHeight);

		int getLvlWidth();
		int getLvlHeight();
		int getTotalTiles();

		virtual void draw() = 0;
		virtual void update(double dt) = 0;

		virtual b2World* GetWorld();

};
