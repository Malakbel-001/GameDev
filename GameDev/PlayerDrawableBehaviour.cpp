#include "PlayerDrawableBehaviour.h"


PlayerDrawableBehaviour::PlayerDrawableBehaviour(SDL_Renderer* sdl_renderer) : DrawableBehaviour(sdl_renderer)
{

}


PlayerDrawableBehaviour::~PlayerDrawableBehaviour()
{
}

void PlayerDrawableBehaviour::Init()
{
	
}

void PlayerDrawableBehaviour::Draw()
{

}

bool PlayerDrawableBehaviour::LoadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if (!spriteSheetTexture.loadFromFile(renderer, "sprites.png"))
	{
		printf("Failed to load sprite sheet texture!\n");
		success = false;
	}
	else
	{
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

	}

	return success;
}
