#include "Level.h"


Level::Level(int _lvlWidth, int _lvlHeight)
	: lvlWigth(_lvlWidth), lvlHeight(_lvlHeight)
{
	world = new b2World(b2Vec2(0.0, 9.81));
}

b2World* Level::GetWorld()
{
	return world;
}

Level::~Level()
{
}

void Level::setLvlWidth(int _lvlWigth)
{
	this->lvlWigth = _lvlWigth;
}

void Level::setLvlHeight(int _lvlHeight)
{
	this->lvlHeight = _lvlHeight;
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

