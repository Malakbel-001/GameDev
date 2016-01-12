
#include <SDL_Main.h>
#include <stdlib.h>
#include <crtdbg.h>
// SDL Portable installation
#include <SDL.h>
#include "Box2D\Box2D.h"
#include "rapidJSON\document.h"
#include "Game.h"
#include "MainMenu.h"


int main(int argc, char* argv[])
{

//	rapidjson::Document document;

	// Initialize SDL.

	//Main Menu
	//MainMenu* menu = new MainMenu();
	//HelpMenu* help = new HelpMenu();
	
	// Give us time to see the window.
	Game* game = new Game();
	
	// Always be sure to clean up
	delete game;
	
	SDL_Quit();

	return 0;
}