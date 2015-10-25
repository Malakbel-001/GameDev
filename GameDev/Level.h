#pragma once
#include <vector>
#include "header_loader.h"
#include "Box2D\Box2D.h"
#include "Camera.h"

class Level
{
	private:
		// stuff

	protected:
		int tileWitdh, tileHeight;
		int lvlWigth, lvlHeight, lvlTotalTiles, lvlTotalDiffrentTiles;
		b2World* world;
		Camera* camera;
		int LevelTiles;
		SDL_Texture* tileSheet;
		std::vector<SDL_Rect> tileCrops;

	public:
		Level(int _lvlWidth, int _lvlHeight);
		virtual ~Level();

		virtual void setLvlWidth(int _lvlWidth);
		virtual void setLvlHeight(int _lvlHeight);

		SDL_Texture* getTileSheet();

		int getLvlWidth();
		int getLvlHeight();
		int getTotalTiles();
		int getTotalDiffrentTiles();
		std::vector<SDL_Rect> getTileCrops();

		virtual void draw() = 0;
		virtual void update(double dt) = 0;

		virtual b2World* GetWorld();

};
