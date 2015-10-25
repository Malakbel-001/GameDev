#include "Level.h"


Level::Level(int _lvlWidth, int _lvlHeight)
	: lvlWigth(_lvlWidth), lvlHeight(_lvlHeight)
{
	world = new b2World(b2Vec2(0.0, 9.8));
	this->tileLoader = nullptr;
}

b2World* Level::GetWorld()
{
	return world;
}

Level::~Level()
{
	// TODO: delete box2D pointer
	SDL_DestroyTexture(tileSheet);
	delete tileLoader;
}

void Level::setLvlWidth(int _lvlWigth)
{
	this->lvlWigth = _lvlWigth;
}

void Level::setLvlHeight(int _lvlHeight)
{
	this->lvlHeight = _lvlHeight;
}

SDL_Texture* Level::getTileSheet()
{
	return this->tileSheet;
}

int Level::getLvlHeight()
{
	return this->lvlHeight;
}

int Level::getLvlWidth()
{
	return this->lvlWigth;
}

int Level::getTotalTiles()
{
	return this->lvlTotalTiles;
}

int Level::getTotalDiffrentTiles()
{
	return this->lvlTotalDiffrentTiles;
}