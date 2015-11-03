#include "GroundDrawableBehaviour.h"


GroundDrawableBehaviour::GroundDrawableBehaviour()
{
}


DrawableBehaviour* GroundDrawableBehaviour::EmptyClone()
{
	return new GroundDrawableBehaviour();
}


GroundDrawableBehaviour::~GroundDrawableBehaviour()
{
}

void GroundDrawableBehaviour::Draw(SDL_Renderer* renderer)
{
	std::cout << "aaa";

	LoadMedia(renderer);
	// Render current frame SCREEN SIZE NOT YET SET!!!

	spriteSheetTexture->render(renderer, body->GetPosition().x, body->GetPosition().y);

	//Go to next frame 
	++currentFrame;

	//Cycle animation 
	if (currentFrame / IDLE_ANIMATION_FRAMES >= IDLE_ANIMATION_FRAMES)
	{
		currentFrame = 0;
	}
}

bool GroundDrawableBehaviour::LoadMedia(SDL_Renderer* renderer)
{
	//Loading success flag
	bool success = true;
	
	//Load sprite sheet texture
	if (!spriteSheetTexture->loadFromFile(renderer, "brown-square.jpg"))
	{
		printf("Failed to load sprite sheet texture!\n");
		success = false;
	}
	else
	{

	}

	return success;
}