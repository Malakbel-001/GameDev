#include "TileLoader.h"

TileLoader::TileLoader(Level* lvl)
{
	this->levelHeight = lvl->getLvlHeight();
	this->levelWidth = lvl->getLvlWidth();
	this->levelTotalTiles = lvl->getTotalTiles();

	this->tileHeight = 80;
	this->tileWidth = 80;
}

TileLoader::~TileLoader() { }

void TileLoader::setTiles(Tile tiles[])
{
	//The tile offsets
	int x = 0, y = 0;

	//Open the map
	//std::ifstream map("39_tiling/lazy.map");
	std::ifstream map("Resources/lazy.map");

	//If the map couldn't be loaded
	//if (map)
	if (!map)
	{
		printf("Unable to load map file!\n");
		tilesLoaded = false;
	}
	else
	{
		//Initialize the tiles
		for (int i = 0; i < TOTAL_TILES; ++i)
		{
			//Determines what kind of tile will be made
			int tileType = -1;

			//Read tile from map file
			map >> tileType;

			//If the was a problem in reading the map
			if (map.fail())
			{
				//Stop loading map
				printf("Error loading map: Unexpected end of file!\n");
				tilesLoaded = false;
				break;
			}

			//If the number is a valid tile number
			if ((tileType >= 0) && (tileType < this-levelTotalTiles))
			{
				tiles[i] = new Tile(x, y, tileType);
			}
			//If we don't recognize the tile type
			else
			{
				//Stop loading map
				printf("Error loading map: Invalid tile type at %d!\n", i);
				tilesLoaded = false;
				break;
			}

			//Move to next tile spot
			x += this->levelWidth;

			//If we've gone too far
			if (x >= this->levelWidth)
			{
				//Move back
				x = 0;

				//Move to the next row
				y += this->tileHeight;
			}
		}

		//Clip the sprite sheet
		if (tilesLoaded)
		{
			gTileClips[TILE_RED].x = 0;
			gTileClips[TILE_RED].y = 0;
			gTileClips[TILE_RED].w = this->levelWidth;
			gTileClips[TILE_RED].h = this->tileHeight;

			gTileClips[TILE_GREEN].x = 0;
			gTileClips[TILE_GREEN].y = 80;
			gTileClips[TILE_GREEN].w = this->levelWidth;
			gTileClips[TILE_GREEN].h = this->tileHeight;

			gTileClips[TILE_BLUE].x = 0;
			gTileClips[TILE_BLUE].y = 160;
			gTileClips[TILE_BLUE].w = this->levelWidth;
			gTileClips[TILE_BLUE].h = this->tileHeight;

			gTileClips[TILE_TOPLEFT].x = 80;
			gTileClips[TILE_TOPLEFT].y = 0;
			gTileClips[TILE_TOPLEFT].w = this->levelWidth;
			gTileClips[TILE_TOPLEFT].h = this->tileHeight;

			gTileClips[TILE_LEFT].x = 80;
			gTileClips[TILE_LEFT].y = 80;
			gTileClips[TILE_LEFT].w = this->levelWidth;
			gTileClips[TILE_LEFT].h = this->tileHeight;

			gTileClips[TILE_BOTTOMLEFT].x = 80;
			gTileClips[TILE_BOTTOMLEFT].y = 160;
			gTileClips[TILE_BOTTOMLEFT].w = this->levelWidth;
			gTileClips[TILE_BOTTOMLEFT].h = this->tileHeight;

			gTileClips[TILE_TOP].x = 160;
			gTileClips[TILE_TOP].y = 0;
			gTileClips[TILE_TOP].w = this->levelWidth;
			gTileClips[TILE_TOP].h = this->tileHeight;

			gTileClips[TILE_CENTER].x = 160;
			gTileClips[TILE_CENTER].y = 80;
			gTileClips[TILE_CENTER].w = this->levelWidth;
			gTileClips[TILE_CENTER].h = this->tileHeight;

			gTileClips[TILE_BOTTOM].x = 160;
			gTileClips[TILE_BOTTOM].y = 160;
			gTileClips[TILE_BOTTOM].w = this->levelWidth;
			gTileClips[TILE_BOTTOM].h = this->tileHeight;

			gTileClips[TILE_TOPRIGHT].x = 240;
			gTileClips[TILE_TOPRIGHT].y = 0;
			gTileClips[TILE_TOPRIGHT].w = this->levelWidth;
			gTileClips[TILE_TOPRIGHT].h = this->tileHeight;

			gTileClips[TILE_RIGHT].x = 240;
			gTileClips[TILE_RIGHT].y = 80;
			gTileClips[TILE_RIGHT].w = this->levelWidth;
			gTileClips[TILE_RIGHT].h = this->tileHeight;

			gTileClips[TILE_BOTTOMRIGHT].x = 240;
			gTileClips[TILE_BOTTOMRIGHT].y = 160;
			gTileClips[TILE_BOTTOMRIGHT].w = this->levelWidth;
			gTileClips[TILE_BOTTOMRIGHT].h = this->tileHeight;
		}
}