#include "PlayerDrawableBehaviour.h"
#include "Entity.h"


PlayerDrawableBehaviour::PlayerDrawableBehaviour(SDL_Renderer* renderer, int screenwidth, int screenheight) : DrawableBehaviour(renderer, screenwidth, screenheight)
{
	
}


PlayerDrawableBehaviour::~PlayerDrawableBehaviour()
{
}

void PlayerDrawableBehaviour::Draw()
{
	sprites = walkSprites;
	float xx = 1;
	float yy = 20;
	float ratio = (xx / yy);
	// Render current frame SCREEN SIZE NOT YET SET!!!
	float xpos = entity->GetXPos() / ratio;
	float ypos = entity->GetYPos() / ratio;
	SDL_Rect* currentClip = &sprites[currentFrame / sprites.size()];
	spriteSheetTexture->render(renderer, xpos, ypos, currentClip);
	
	//Go to next frame 
	++currentFrame;

	//Cycle animation 
	if (currentFrame / sprites.size() >= sprites.size())
	{
		currentFrame = 0;
	}
}

void PlayerDrawableBehaviour::SetSprites(vector<SDL_Rect> sdl_sprites)
{
	sprites = sdl_sprites;
}

bool PlayerDrawableBehaviour::LoadMedia()
{
	//Loading success flag
	bool success = true;

	spritesheetPath = "";
	spritesheetName = "sprites.png";

	//Load sprite sheet texture
	if (!spriteSheetTexture->loadFromFile(renderer, spritesheetPath + spritesheetName))
	{
		printf("Failed to load spritesheet! \n");
		success = false;
	}
	else
	{
		idleSprites.resize(IDLE_ANIMATION_FRAMES);

		idleSprites[0].x = 4;
		idleSprites[0].y = 0;
		idleSprites[0].w = 30;
		idleSprites[0].h = 40;

		idleSprites[1].x = idleSprites[0].x + idleSprites[0].w;
		idleSprites[1].y = 0;
		idleSprites[1].w = 30;
		idleSprites[1].h = 40;

		idleSprites[2].x = idleSprites[1].x + idleSprites[1].w;
		idleSprites[2].y = 0;
		idleSprites[2].w = 30;
		idleSprites[2].h = 40;

		walkSprites.resize(WALK_ANIMATION_FRAMES);

		walkSprites[0].x = 107;
		walkSprites[0].y = 0;
		walkSprites[0].w = 30;
		walkSprites[0].h = 40;

		walkSprites[1].x = walkSprites[0].x + walkSprites[0].w;
		walkSprites[1].y = 0;
		walkSprites[1].w = 30;
		walkSprites[1].h = 40;

		walkSprites[2].x = walkSprites[1].x + walkSprites[1].w;
		walkSprites[2].y = 0;
		walkSprites[2].w = 30;
		walkSprites[2].h = 40;

		walkSprites[3].x = walkSprites[2].x + walkSprites[2].w;
		walkSprites[3].y = 0;
		walkSprites[3].w = 30;
		walkSprites[3].h = 40;

		walkSprites[4].x = walkSprites[3].x + walkSprites[3].w;
		walkSprites[4].y = 0;
		walkSprites[4].w = 30;
		walkSprites[4].h = 40;

		walkSprites[5].x = walkSprites[4].x + walkSprites[4].w;
		walkSprites[5].y = 0;
		walkSprites[5].w = 30;
		walkSprites[5].h = 40;

		walkSprites[6].x = walkSprites[5].x + walkSprites[5].w;
		walkSprites[6].y = 0;
		walkSprites[6].w = 30;
		walkSprites[6].h = 40;

		walkSprites[7].x = walkSprites[6].x + walkSprites[6].w;
		walkSprites[7].y = 0;
		walkSprites[7].w = 30;
		walkSprites[7].h = 40;

		walkSprites[8].x = walkSprites[7].x + walkSprites[7].w;
		walkSprites[8].y = 0;
		walkSprites[8].w = 30;
		walkSprites[8].h = 40;

		sprites = idleSprites;
	}

	return success;
}

PlayerDrawableBehaviour* PlayerDrawableBehaviour::EmptyClone()
{
	return new PlayerDrawableBehaviour(renderer, screenWidth, screenHeight);
}