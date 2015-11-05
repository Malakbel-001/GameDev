#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include "Tile.h"
#include "LTexture.h"

class Level;

class TileLoader
{
	private:
		int levelWidth, levelHeight, levelTotalTiles, levelTotalDiffrentTiles;
		int tileWidth, tileHeight;

		LTexture* tileSheet;
		SDL_Rect tileCrop;

		void SetTileTypes();

	protected:
		// stuff

	public:
		TileLoader(Level* lvl);
		virtual ~TileLoader();

		void SetTiles(std::vector<Tile*> tiles);
};
