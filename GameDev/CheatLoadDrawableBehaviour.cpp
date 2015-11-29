#include "CheatLoadDrawableBehaviour.h"

CheatLoadDrawableBehaviour::CheatLoadDrawableBehaviour(SDL_Renderer* renderer, Sprite* _sprite, int screenwidth, int screenheight) : DrawableBehaviour(renderer, _sprite, screenwidth, screenheight)
{
	sprite->SetAnimationSet(EntityState::WALKINGRIGHT);
}


CheatLoadDrawableBehaviour::~CheatLoadDrawableBehaviour()
{
}

void CheatLoadDrawableBehaviour::Draw()
{
	// Render current frame SCREEN SIZE NOT YET SET!!!
	float xpos = 20;
	float ypos = 20;

	sprite->GetSpritesheet()->render(renderer, xpos, ypos, sprite->GetAnimationFrame(EntityState::WALKINGRIGHT, currentFrame));

	//Go to next frame 
	++currentFrame;
	int size = sprite->GetAnimationSize();
	//Cycle animation 

	if (currentFrame >= size)
	{
		currentFrame = 0;
	}
}

CheatLoadDrawableBehaviour* CheatLoadDrawableBehaviour::EmptyClone()
{
	return new CheatLoadDrawableBehaviour(renderer, sprite, screenWidth, screenHeight);
}