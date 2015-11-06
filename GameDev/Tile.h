#pragma once
#include "header_loader.h"
#include <iostream>

class Tile
{
private:
	//The attributes of the tile
	SDL_Rect mBox;

	//The tile type
	int mType;

	//Tile constants
	int TILE_WIDTH = 80;
	int TILE_HEIGHT = 80;
	int TOTAL_TILES = 192;
	int TOTAL_TILE_SPRITES = 12;

	//The different tile sprites
	int TILE_RED = 0;
	int TILE_GREEN = 1;
	int TILE_BLUE = 2;
	int TILE_CENTER = 3;
	int TILE_TOP = 4;
	int TILE_TOPRIGHT = 5;
	int TILE_RIGHT = 6;
	int TILE_BOTTOMRIGHT = 7;
	int TILE_BOTTOM = 8;
	int TILE_BOTTOMLEFT = 9;
	int TILE_LEFT = 10;
	int TILE_TOPLEFT = 11;

	SDL_Texture* tileText;
	// TODO:: Fix
	SDL_Rect gTileClips[12];
public:
	//Initializes position and type
	Tile(int x, int y, int tileType);
	virtual ~Tile();

	//Shows the tile
	void render(SDL_Rect& camera);

	//Get the tile type
	int getType();

	//Get the collision box
	SDL_Rect getBox();
};
