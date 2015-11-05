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
	// Render current frame SCREEN SIZE NOT YET SET!!!
	SDL_Rect* currentClip = &sprites[currentFrame / sprites.size()];
	spriteSheetTexture->render(renderer, entity->GetXPos(), entity->GetYPos(), currentClip);

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

		/*walkSprites[0].x = 107;
		walkSprites[0].y = 1;
		walkSprites[0].w = 30;
		walkSprites[0].h = 40;

		walkSprites[1].x = walkSprites[0].x + walkSprites[0].w + 2;
		walkSprites[1].y = 1;
		walkSprites[1].w = 28;
		walkSprites[1].h = 41;*/

		//walkSprites[2].x = walkSprites[1].x + walkSprites[1].w + 1;

		walkSprites[0].x = 107+30+28+3;
		walkSprites[0].y = 1;
		walkSprites[0].w = 32;
		walkSprites[0].h = 40;

		walkSprites[1].x = walkSprites[0].x + walkSprites[0].w + 1;
		walkSprites[1].y = 1;
		walkSprites[1].w = 32;
		walkSprites[1].h = 41;

		walkSprites[2].x = walkSprites[1].x + walkSprites[1].w + 2;
		walkSprites[2].y = 1;
		walkSprites[2].w = 27;
		walkSprites[2].h = 41;

		walkSprites[3].x = walkSprites[2].x + walkSprites[2].w + 4;
		walkSprites[3].y = 1;
		walkSprites[3].w = 29;
		walkSprites[3].h = 40;

		walkSprites[4].x = walkSprites[3].x + walkSprites[3].w + 3;
		walkSprites[4].y = 1;
		walkSprites[4].w = 32;
		walkSprites[4].h = 40;
		
		walkSprites[5].x = walkSprites[4].x + walkSprites[4].w + 0;
		walkSprites[5].y = 1;
		walkSprites[5].w = 36;
		walkSprites[5].h = 37;
		
		walkSprites[6].x = walkSprites[5].x + walkSprites[5].w + 0;
		walkSprites[6].y = 1;
		walkSprites[6].w = 31;
		walkSprites[6].h = 40;

		sprites = idleSprites;
	}

	return success;
}

PlayerDrawableBehaviour* PlayerDrawableBehaviour::EmptyClone()
{
	return new PlayerDrawableBehaviour(renderer, screenWidth, screenHeight);
}