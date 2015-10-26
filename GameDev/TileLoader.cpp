#include "TileLoader.h"
#include "Level.h"

TileLoader::TileLoader(Level* lvl)
{
	this->levelHeight = lvl->GetLvlHeight();
	this->levelWidth = lvl->GetLvlWidth();
	this->levelTotalTiles = lvl->GetTotalTiles();
	this->levelTotalDiffrentTiles = lvl->GetTotalDiffrentTiles();

	this->tileHeight = 80;
	this->tileWidth = 80;

	this->tileSheet = lvl->GetTileSheet();

	tileSheet = lvl->GetTileSheet();
}

void TileLoader::SetTileTypes()
{
	this->TILE_RED = 0;
	this->TILE_GREEN = 1;
	this->TILE_BLUE = 2;
	this->TILE_CENTER = 3;
	this->TILE_TOP = 4;
	this->TILE_TOPRIGHT = 5;
	this->TILE_RIGHT = 6;
	this->TILE_BOTTOMRIGHT = 7;
	this->TILE_BOTTOM = 8;
	this->TILE_BOTTOMLEFT = 9;
	this->TILE_LEFT = 10;
	this->TILE_TOPLEFT = 11;
}

TileLoader::~TileLoader()
{
	// don't destroy tileSheet, shard pointer with currentLevel in GSM
}

void TileLoader::SetTiles(std::vector<Tile*> tiles)
{
	bool tilesLoaded = true;
	int x = 0, y = 0;

	//Open the map
	std::ifstream map("Resources/maps/test.map");

	//If the map couldn't be loaded
	if (!map)
	{
		std::cout << "Unable to load map file!\n";
		tilesLoaded = false;
	}
	else
	{
		//Initialize the tiles
		for (int i = 0; i < this->levelTotalTiles; ++i)
		{
			//Determines what kind of tile will be made
			int tileType = -1;

			//Read tile from map file
			map >> tileType;

			//If the was a problem in reading the map
			if (map.fail())
			{
				//Stop loading map
				std::cout << "Error reading map: Unexpected end of file!\n";
				tilesLoaded = false;
				break;
			}

			//If the number is a valid tile number
			if ((tileType >= 0) && (tileType < this->levelTotalTiles))
			{
				tiles.push_back(new Tile(x, y, tileType));
			}
			//If we don't recognize the tile type
			else
			{
				//Stop loading map
				printf("Error loading map: Invalid tile type at %d!\n", i);
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
			tileCrop[TILE_RED].x = 0;
			tileCrop[TILE_RED].y = 0;
			tileCrop[TILE_RED].w = this->tileWidth;
			tileCrop[TILE_RED].h = this->tileHeight;

			tileCrop[TILE_GREEN].x = 0;
			tileCrop[TILE_GREEN].y = 80;
			tileCrop[TILE_GREEN].w = this->tileWidth;
			tileCrop[TILE_GREEN].h = this->tileHeight;

			tileCrop[TILE_BLUE].x = 0;
			tileCrop[TILE_BLUE].y = 160;
			tileCrop[TILE_BLUE].w = this->tileWidth;
			tileCrop[TILE_BLUE].h = this->tileHeight;

			tileCrop[TILE_TOPLEFT].x = 80;
			tileCrop[TILE_TOPLEFT].y = 0;
			tileCrop[TILE_TOPLEFT].w = this->tileWidth;
			tileCrop[TILE_TOPLEFT].h = this->tileHeight;

			tileCrop[TILE_LEFT].x = 80;
			tileCrop[TILE_LEFT].y = 80;
			tileCrop[TILE_LEFT].w = this->tileWidth;
			tileCrop[TILE_LEFT].h = this->tileHeight;

			tileCrop[TILE_BOTTOMLEFT].x = 80;
			tileCrop[TILE_BOTTOMLEFT].y = 160;
			tileCrop[TILE_BOTTOMLEFT].w = this->tileWidth;
			tileCrop[TILE_BOTTOMLEFT].h = this->tileHeight;

			tileCrop[TILE_TOP].x = 160;
			tileCrop[TILE_TOP].y = 0;
			tileCrop[TILE_TOP].w = this->tileWidth;
			tileCrop[TILE_TOP].h = this->tileHeight;

			tileCrop[TILE_CENTER].x = 160;
			tileCrop[TILE_CENTER].y = 80;
			tileCrop[TILE_CENTER].w = this->tileWidth;
			tileCrop[TILE_CENTER].h = this->tileHeight;

			tileCrop[TILE_BOTTOM].x = 160;
			tileCrop[TILE_BOTTOM].y = 160;
			tileCrop[TILE_BOTTOM].w = this->tileWidth;
			tileCrop[TILE_BOTTOM].h = this->tileHeight;

			tileCrop[TILE_TOPRIGHT].x = 240;
			tileCrop[TILE_TOPRIGHT].y = 0;
			tileCrop[TILE_TOPRIGHT].w = this->tileWidth;
			tileCrop[TILE_TOPRIGHT].h = this->tileHeight;

			tileCrop[TILE_RIGHT].x = 240;
			tileCrop[TILE_RIGHT].y = 80;
			tileCrop[TILE_RIGHT].w = this->tileWidth;
			tileCrop[TILE_RIGHT].h = this->tileHeight;

			tileCrop[TILE_BOTTOMRIGHT].x = 240;
			tileCrop[TILE_BOTTOMRIGHT].y = 160;
			tileCrop[TILE_BOTTOMRIGHT].w = this->tileWidth;
			tileCrop[TILE_BOTTOMRIGHT].h = this->tileHeight;
		}
	}
}