#include "AnimatedDrawableBehaviour.h"
#include "Entity.h"

AnimatedDrawableBehaviour::AnimatedDrawableBehaviour(SDL_Renderer* renderer, Sprite* _sprite, int screenwidth, int screenheight) : DrawableBehaviour(renderer, _sprite, screenwidth, screenheight)
{
}


AnimatedDrawableBehaviour::~AnimatedDrawableBehaviour()
{
}

void AnimatedDrawableBehaviour::Draw()
{
	// Render current frame SCREEN SIZE NOT YET SET!!!
	float xpos = ((entity->GetXPos() / Ratio) - (camera->GetX() / Ratio)) + ((screenWidth / 2) - (screenWidth / 4));
	float ypos = entity->GetYPos() / Ratio;



	sprite->GetSpritesheet()->render(renderer, xpos, ypos, sprite->GetAnimationFrame(entity->GetState(), currentFrame));

	//Go to next frame 
	++currentFrame;
	int size = sprite->GetAnimationSize();
	//Cycle animation 

	if (currentFrame >= size)
	{
		currentFrame = 0;
	}
}

AnimatedDrawableBehaviour* AnimatedDrawableBehaviour::EmptyClone()
{
	return new AnimatedDrawableBehaviour(renderer, sprite, screenWidth, screenHeight);
}
