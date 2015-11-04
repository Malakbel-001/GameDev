#include "testLevel.h"

testLevel::testLevel(int _lvlWidth, int _lvlHeight)
	: Level(_lvlWidth, _lvlHeight)
{
	this->lvlTotalTiles = 192;
	this->lvlTotalDiffrentTiles = 12;
	this->tileLoader = new TileLoader(this);

}

testLevel::~testLevel() { }

void testLevel::Cleanup() { }


void testLevel::HandleEvents(SDL_Event mainEvent) { }


