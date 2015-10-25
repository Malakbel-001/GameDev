#include "playerWalkingDrawableBehaviour.h"

using namespace std;

playerWalkingDrawableBehaviour::playerWalkingDrawableBehaviour(SDL_Renderer* sdl_renderer)
{
	currentFrame = 0;
	renderer = sdl_renderer;
	LoadMedia();

	sprites[0].x = 107;
	sprites[0].y = 0;
	sprites[0].w = 30;
	sprites[0].h = 40;

	sprites[1].x = sprites[0].x + sprites[0].w;
	sprites[1].y = 0;
	sprites[1].w = 30;
	sprites[1].h = 40;

	sprites[2].x = sprites[1].x + sprites[1].w;
	sprites[2].y = 0;
	sprites[2].w = 30;
	sprites[2].h = 40;

	sprites[3].x = sprites[2].x + sprites[2].w;
	sprites[3].y = 0;
	sprites[3].w = 30;
	sprites[3].h = 40;

	sprites[4].x = sprites[3].x + sprites[3].w;
	sprites[4].y = 0;
	sprites[4].w = 30;
	sprites[4].h = 40;

	sprites[5].x = sprites[4].x + sprites[4].w;
	sprites[5].y = 0;
	sprites[5].w = 30;
	sprites[5].h = 40;

	sprites[6].x = sprites[5].x + sprites[5].w;
	sprites[6].y = 0;
	sprites[6].w = 30;
	sprites[6].h = 40;

	sprites[7].x = sprites[6].x + sprites[6].w;
	sprites[7].y = 0;
	sprites[7].w = 30;
	sprites[7].h = 40;

	sprites[8].x = sprites[7].x + sprites[7].w;
	sprites[8].y = 0;
	sprites[8].w = 30;
	sprites[8].h = 40;
}


playerWalkingDrawableBehaviour::~playerWalkingDrawableBehaviour()
{
}

void playerWalkingDrawableBehaviour::Draw()
{
	//Render current frame 
	SDL_Rect* currentClip = &sprites[currentFrame / WALK_ANIMATION_FRAMES];
	
	// 640x480 is screen size, set values for now...
	spriteSheetTexture.render(renderer, (640 - currentClip->w) / 2, (480 - currentClip->h) / 2, currentClip);

	//Update screen
	SDL_RenderPresent(renderer);

	//Go to next frame 
	++currentFrame;

	//Cycle animation 
	if (currentFrame / WALK_ANIMATION_FRAMES >= WALK_ANIMATION_FRAMES)
	{
		currentFrame = 0;
	}
}

bool playerWalkingDrawableBehaviour::LoadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if (!spriteSheetTexture.loadFromFile(renderer, "sprites.png"))
	{
		printf("Failed to load sprite sheet texture!\n");
		success = false;
	}
}