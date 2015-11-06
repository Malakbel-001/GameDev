#include "EnemyDrawableBehaviour.h"
#include "Entity.h"

EnemyDrawableBehaviour::EnemyDrawableBehaviour(SDL_Renderer* renderer, int screenwidth, int screenheight) : DrawableBehaviour(renderer, screenwidth, screenheight)
{
}


EnemyDrawableBehaviour::~EnemyDrawableBehaviour()
{
}

void EnemyDrawableBehaviour::Draw()
{
	sprites = idleSprites;

	// Render current frame SCREEN SIZE NOT YET SET!!!
	float xpos = entity->GetXPos() / Ratio;
	float ypos = entity->GetYPos() / Ratio;
	SDL_Rect* currentClip = &sprites[currentFrame / sprites.size()];
	
	spriteSheetTexture->render(renderer, xpos+10, ypos+10, currentClip);

	//Go to next frame 
	++currentFrame;

	//Cycle animation 
	if (currentFrame / sprites.size() >= sprites.size())
	{
		currentFrame = 0;
	}
}

void EnemyDrawableBehaviour::SetSprites(vector<SDL_Rect> sdl_sprites)
{
	sprites = sdl_sprites;
}

bool EnemyDrawableBehaviour::LoadMedia()
{
	//Loading success flag
	bool success = true;

	spritesheetPath = "";
	spritesheetName = "plant.png";

	//Load sprite sheet texture
	if (!spriteSheetTexture->loadFromFile(renderer, spritesheetPath + spritesheetName))
	{
		printf("Failed to load spritesheet! \n");
		success = false;
	}
	else
	{
		idleSprites.resize(IDLE_ANIMATION_FRAMES);

		idleSprites[0].x = 6;
		idleSprites[0].y = 395;
		idleSprites[0].w = 45;
		idleSprites[0].h = 50;

		idleSprites[1].x = idleSprites[0].x + idleSprites[0].w;
		idleSprites[1].y = 395;
		idleSprites[1].w = 45;
		idleSprites[1].h = 50;

		idleSprites[2].x = idleSprites[1].x + idleSprites[1].w + 10;
		idleSprites[2].y = 395;
		idleSprites[2].w = 45;
		idleSprites[2].h = 50;

		idleSprites[3].x = idleSprites[2].x + idleSprites[2].w + 10;
		idleSprites[3].y = 395;
		idleSprites[3].w = 45;
		idleSprites[3].h = 50;

		idleSprites[4].x = idleSprites[3].x + idleSprites[3].w + 10;
		idleSprites[4].y = 395;
		idleSprites[4].w = 45;
		idleSprites[4].h = 50;

		idleSprites[5].x = idleSprites[4].x + idleSprites[4].w + 10;
		idleSprites[5].y = 395;
		idleSprites[5].w = 45;
		idleSprites[5].h = 50;

		idleSprites[6].x = idleSprites[5].x + idleSprites[5].w + 10;
		idleSprites[6].y = 395;
		idleSprites[6].w = 45;
		idleSprites[6].h = 50;

		idleSprites[7].x = idleSprites[6].x + idleSprites[6].w + 10;
		idleSprites[7].y = 395;
		idleSprites[7].w = 45;
		idleSprites[7].h = 50;

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

		walkSprites[0].x = 107 + 30 + 28 + 3;
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

EnemyDrawableBehaviour* EnemyDrawableBehaviour::EmptyClone()
{
	return new EnemyDrawableBehaviour(renderer, screenWidth, screenHeight);
}