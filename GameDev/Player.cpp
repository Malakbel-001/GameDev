#include "Player.h"
#include "GameStateManager.h"

Player::Player(Camera* cam)
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

	this->camera = cam;

}
Entity* Player::EmptyClone()
{
	return new Player(camera);
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
	int SCREEN_WIDTH, SCREEN_HEIGHT;
	SDL_GetWindowSize(GameStateManager::Instance()->sdlInitializer->GetWindow(), &SCREEN_WIDTH, &SCREEN_HEIGHT);

	//Center the camera over the dot
	camera->SetX( (mBox.x + WIDTH / 2) - SCREEN_WIDTH / 2);
	camera->SetY( (mBox.y + HEIGHT / 2) - SCREEN_HEIGHT / 2);

	//Keep the camera in bounds
	if (camera->GetX() < 0)
		camera->SetX(0);
	
	if (camera->GetY() < 0)
		camera->SetY(0);

	if (camera->GetX() > LEVEL_WIDTH - camera->GetWidth())
		camera->SetX(LEVEL_WIDTH - camera->GetWidth());

	if (camera->GetY() > LEVEL_HEIGHT - camera->GetHeight())
		camera->SetY( LEVEL_HEIGHT - camera->GetHeight());
}

void Player::Draw()
{
	//Show the dot
	//gDotTexture.render(mBox.x - camera.x, mBox.y - camera.y);
	GameStateManager::Instance()->sdlInitializer->RenderToScreen(mBox.x - camera->GetX(), mBox.y - camera->GetY(), texture, NULL);
}
