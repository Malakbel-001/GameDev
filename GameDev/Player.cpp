#include "Player.h"
#include "GameStateManager.h"

Player::Player()
{
	//Initialize the collision box
	mBox.x = 0;
	mBox.y = 0;
	mBox.w = WIDTH;
	mBox.h = HEIGHT;

	//Initialize the velocity
	mVelX = 0;
	mVelY = 0;

	texture = IMG_LoadTexture(GameStateManager::Instance()->sdlInitializer->getRenderer(), "Resourses/images/ball.bmp");
}

Player::~Player()
{
}

void Player::handleEvent(SDL_Event& e)
{
	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY -= DOT_VEL; break;
		case SDLK_DOWN: mVelY += DOT_VEL; break;
		case SDLK_LEFT: mVelX -= DOT_VEL; break;
		case SDLK_RIGHT: mVelX += DOT_VEL; break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY += DOT_VEL; break;
		case SDLK_DOWN: mVelY -= DOT_VEL; break;
		case SDLK_LEFT: mVelX += DOT_VEL; break;
		case SDLK_RIGHT: mVelX -= DOT_VEL; break;
		}
	}
}
/*
void Player::move(Tile *tiles[])
{
	//Move the dot left or right
	mBox.x += mVelX;

	//If the dot went too far to the left or right or touched a wall
	if ((mBox.x < 0) || (mBox.x + WIDTH > LEVEL_WIDTH) || touchesWall(mBox, tiles))
	{
		//move back
		mBox.x -= mVelX;
	}

	//Move the dot up or down
	mBox.y += mVelY;

	//If the dot went too far up or down or touched a wall
	if ((mBox.y < 0) || (mBox.y + HEIGHT > LEVEL_HEIGHT) || touchesWall(mBox, tiles))
	{
		//move back
		mBox.y -= mVelY;
	}
}
*/

// TODO: Make camara an class
void Player::setCamera(SDL_Rect& camera)
{
	int SCREEN_WIDTH, SCREEN_HEIGHT;
	SDL_GetWindowSize(GameStateManager::Instance()->sdlInitializer->getWindow(), &SCREEN_WIDTH, &SCREEN_HEIGHT);

	//Center the camera over the dot
	camera.x = (mBox.x + WIDTH / 2) - SCREEN_WIDTH / 2;
	camera.y = (mBox.y + HEIGHT / 2) - SCREEN_HEIGHT / 2;

	//Keep the camera in bounds
	if (camera.x < 0)
		camera.x = 0;
	
	if (camera.y < 0)
		camera.y = 0;

	if (camera.x > LEVEL_WIDTH - camera.w)
		camera.x = LEVEL_WIDTH - camera.w;

	if (camera.y > LEVEL_HEIGHT - camera.h)
		camera.y = LEVEL_HEIGHT - camera.h;
}

void Player::draw(SDL_Rect& camera)
{
	//Show the dot
	//gDotTexture.render(mBox.x - camera.x, mBox.y - camera.y);
	GameStateManager::Instance()->sdlInitializer->RenderToScreen(mBox.x - camera.x, mBox.y - camera.y, texture, NULL);
}