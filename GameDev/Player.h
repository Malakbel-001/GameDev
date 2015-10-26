#pragma once
#include "Actor.h"
#include "header_loader.h"
#include "Camera.h"

class Player :
	public Actor
{
private:
	//Collision box of the dot
	SDL_Texture* texture;
	SDL_Rect mBox;

	//The velocity of the dot
	int mVelX, mVelY;

	Camera* camera;
public:
	Player(Camera* cam);

	virtual ~Player();

	//The dimensions of the dot
	int WIDTH, HEIGHT;

	// TODO:: Move to level
	int LEVEL_WIDTH = 1280, LEVEL_HEIGHT = 960;

	//Maximum axis velocity of the dot
	static const int DOT_VEL = 10;

	//Takes key presses and adjusts the dot's velocity
	void HandleEvent(SDL_Event& e);

	//Moves the dot and check collision against tiles
	//void move(Tiles *tiles[]);

	//Centers the camera over the dot
	void SetCamera();

	//Shows the dot on the screen
	void Draw();

	virtual Entity* EmptyClone();
};
