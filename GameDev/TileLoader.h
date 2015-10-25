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
		int levelWidth, levelHeight, levelTotalTiles, levelTotalDiffrentTiles;
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

		SDL_Texture* tileSheet;
		std::vector<SDL_Rect> tileCrop;

		void setTileTypes();

	protected:
		// stuff

	public:
		TileLoader(Level* lvl);
		virtual ~TileLoader();

		void setTiles(std::vector<Tile*> tiles);
};

