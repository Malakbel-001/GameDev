#include "Tile.h"
#include "GameStateManager.h"

Tile::Tile(int x, int y, int tileType)
{
	//Get the offsets
	mBox.x = x;
	mBox.y = y;

	//Set the collision box
	mBox.w = TILE_WIDTH;
	mBox.h = TILE_HEIGHT;

	//Get the tile type
	mType = tileType;

	//tileText = IMG_LoadTexture(GameStateManager::Instance()->sdlInitializer->GetRenderer(), "Resourses/images/tileset.png");
	if (tileText == NULL)
	{
		std::cout << "Coudn't load tileSet";
	}
	else
	{
		// get tileText witdh and height
		//SDL_QueryTexture(tileText, nullptr, nullptr, &)
	}
}

Tile::~Tile() { }

void Tile::render(SDL_Rect& camera)
{
	//If the tile is on screen
	//if (checkCollision(camera, mBox))
	//{
	//	//Show the tile
	//	//gTileTexture.render(mBox.x - camera.x, mBox.y - camera.y, &gTileClips[mType]);
	//}

	//GameStateManager::Instance()->sdlInitializer->RenderToScreen(mBox.x - camera.x, mBox.y - camera.y, tileText, &gTileClips[mType]);
}

int Tile::getType()
{
	return mType;
}

SDL_Rect Tile::getBox()
{
	return mBox;
}