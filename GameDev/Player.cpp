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

	texture = IMG_LoadTexture(GameStateManager::Instance()->sdlInitializer->GetRenderer(), "Resourses/images/ball.bmp");
	SDL_QueryTexture(texture, NULL, NULL, &WIDTH, &HEIGHT);
}

Entity* Player::EmptyClone()
{
	return new Player();
}

Player::~Player()
{
}

void Player::HandleEvent(SDL_Event& e)
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
void Player::SetCamera()
{
	
}

void Player::Draw()
{
	
}
