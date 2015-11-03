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

void testLevel::Update(double dt)
{

}

void testLevel::Draw()
{
	drawableContainer->Draw();

	/*
	SDL_Rect r;
	r.x = 50;
	r.y = 50;
	r.w = 50;
	r.h = 50;

	// Set render color to blue ( rect will be rendered in this color )
	SDL_SetRenderDrawColor(GameStateManager::Instance()->sdlInitializer->GetRenderer(), 0, 0, 255, 255);

	// Render rect
	SDL_RenderFillRect(GameStateManager::Instance()->sdlInitializer->GetRenderer(), &r);

	// reset the renderer to black, full alpra
	SDL_SetRenderDrawColor(GameStateManager::Instance()->sdlInitializer->GetRenderer(), 0, 0, 0, 255);

	// Render the rect to the screen
	SDL_RenderPresent(GameStateManager::Instance()->sdlInitializer->GetRenderer());

	// draw the tiles
	for (size_t i = 0; i < tileCrops.size(); ++i)
	{
		tileCrops.at(i);
	}
	*/
}