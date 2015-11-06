#include "TileLoader.h"
#include "Level.h"

TileLoader::TileLoader(Level* lvl)
{
	this->levelHeight = lvl->GetLvlHeight();
	this->levelWidth = lvl->GetLvlWidth();

	this->tileHeight = 80;
	this->tileWidth = 80;
}

void TileLoader::SetTileTypes()
{ }

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
	}
}