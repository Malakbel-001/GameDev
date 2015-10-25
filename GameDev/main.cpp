// SDL Portable installation
#include "SDL.h"
#include "Box2D\Box2D.h"
#include "rapidJSON\document.h"
#include "Game.h"
#include "MainMenu.h"
#include "HelpMenu.h"

int main(int argc, char* argv[])
{

	rapidjson::Document document;

	b2Vec2 gravity(0, -9.8); //normal earth gravity, 9.8 m/s/s straight down!


	b2World* myWorld = new b2World(gravity);
	// Initialize SDL.

	//Main Menu
	MainMenu* menu = new MainMenu();
	//HelpMenu* help = new HelpMenu();
	
	// Give us time to see the window.
	Game* game = new Game();
		

	// Always be sure to clean up
	
	return 0;
}