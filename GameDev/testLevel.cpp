#include "testLevel.h"

testLevel::testLevel(int _lvlWidth, int _lvlHeight)
	: Level(_lvlWidth, _lvlHeight)
{
	this->lvlTotalTiles = 192;
	this->lvlTotalDiffrentTiles = 12;
}

testLevel::~testLevel() { }

void testLevel::cleanup()
{
	
}


void testLevel::handleEvents(SDL_Event mainEvent)
{

}

void testLevel::update(double dt)
{

}

void testLevel::draw()
{
	SDL_Rect r;
	r.x = 50;
	r.y = 50;
	r.w = 50;
	r.h = 50;

	SDL_SetRenderDrawColor(GameStateManager::Instance()->sdlInitializer->getRenderer(), 255, 0, 0, 255);
	// Set render color to blue ( rect will be rendered in this color )
	SDL_SetRenderDrawColor(GameStateManager::Instance()->sdlInitializer->getRenderer(), 0, 0, 255, 255);

	// Render rect
	SDL_RenderFillRect(GameStateManager::Instance()->sdlInitializer->getRenderer(), &r);

	// Render the rect to the screen
	SDL_RenderPresent(GameStateManager::Instance()->sdlInitializer->getRenderer());


}