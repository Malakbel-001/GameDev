#include "DrawableBehaviour.h"


DrawableBehaviour::DrawableBehaviour()
{
	currentFrame = 0;
}


DrawableBehaviour::~DrawableBehaviour()
{
}

void DrawableBehaviour::SetSprites(vector<SDL_Rect> sdl_sprites)
{
	sprites = sdl_sprites;
}

DrawableBehaviour* DrawableBehaviour::EmptyClone()
{
	return new DrawableBehaviour();
}

void DrawableBehaviour::Draw(SDL_Renderer* renderer, LTexture* spriteSheetTexture)
{
	// Render current frame SCREEN SIZE NOT YET SET!!!
	SDL_Rect* currentClip = &sprites[currentFrame / sprites.size()];	
	spriteSheetTexture->render(renderer, (640 - currentClip->w) / 2, (480 - currentClip->h) / 2, currentClip);

	//Go to next frame 
	++currentFrame;

	//Cycle animation 
	if (currentFrame / sprites.size() >= sprites.size())
	{
		currentFrame = 0;
	}
}