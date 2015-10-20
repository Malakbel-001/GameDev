#pragma once
#include "Actor.h"
#include <SDL.h>
#include <SDL_image.h>

class Player :
	public Actor
{
private:
	//Collision box of the dot
	SDL_Texture* texture;
	SDL_Rect mBox;

	//The velocity of the dot
	int mVelX, mVelY;

public:
	Player();
	// maybe for multieplayer ???
	virtual ~Player();

	//The dimensions of the dot
	static const int WIDTH = 20;
	static const int HEIGHT = 20;

	// TODO:: Move to level
	int LEVEL_WIDTH = 1280, LEVEL_HEIGHT = 960;

	//Maximum axis velocity of the dot
	static const int DOT_VEL = 10;

	//Takes key presses and adjusts the dot's velocity
	void handleEvent(SDL_Event& e);

	//Moves the dot and check collision against tiles
	//void move(Tiles *tiles[]);

	//Centers the camera over the dot
	void setCamera(SDL_Rect& camera);

	//Shows the dot on the screen
	void draw(SDL_Rect& camera);
};

