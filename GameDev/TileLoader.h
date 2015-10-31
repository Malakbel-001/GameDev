#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include "Tile.h"

class Level;

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

		void SetTileTypes();

	protected:
		// stuff

	public:
		TileLoader(Level* lvl);
		virtual ~TileLoader();

		void SetTiles(std::vector<Tile*> tiles);
};

