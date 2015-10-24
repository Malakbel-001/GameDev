#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <SDL.h>
#include "Tile.h"
#include "Level.h"

class TileLoader
{
	private:
		int levelWidth, levelHeight, levelTotalTiles;
		int tileWidth, tileHeight;

		int TILE_RED;
		int TILE_GREEN;
		int TILE_BLUE;
		int TILE_CENTER;
		int TILE_TOP;
		int TILE_TOPRIGHT;
		int TILE_RIGHT;
		int TILE_BOTTOMRIGHT;
		int TILE_BOTTOM;
		int TILE_BOTTOMLEFT;
		int TILE_LEFT;
		int TILE_TOPLEFT;

		SDL_Texture 

	protected:
		// stuff

	public:
		TileLoader(Level* lvl);
		virtual ~TileLoader();

		void setTiles(Tile tiles[]);
};

