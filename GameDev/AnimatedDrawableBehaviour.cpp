#include "AnimatedDrawableBehaviour.h"
#include "Entity.h"

AnimatedDrawableBehaviour::AnimatedDrawableBehaviour(SDL_Renderer* renderer, Sprite* _sprite, int screenwidth, int screenheight) : DrawableBehaviour(renderer, _sprite, screenwidth, screenheight)
{
}


AnimatedDrawableBehaviour::~AnimatedDrawableBehaviour()
{
}

void AnimatedDrawableBehaviour::Draw(bool cycle)
{
	if (entity->ShouldDraw()){
		// Render current frame SCREEN SIZE NOT YET SET!!!
		float xpos = ((entity->GetXpos() / Ratio) - (camera->GetX() / Ratio)) + ((screenWidth / 2) - (screenWidth / 4));
		float ypos = entity->GetYpos() / Ratio;

		ypos = ypos - sprite->GetFrameYOffSet(currentFrame); // /3
		xpos = xpos - sprite->GetFrameXOffSet(currentFrame); // /3


		sprite->GetSpritesheet()->render(renderer, xpos, ypos, (entity->GetAngle() * 90), sprite->GetAnimationFrame(entity->GetState(), currentFrame), entity->GetFlipped()); // /3

		//Go to next frame 
		if (cycle) {
				++currentFrame;

			int size = sprite->GetAnimationSize(entity->GetState());
			//Cycle animation 

			if (currentFrame >= size) // /3
			{
				currentFrame = 0;
			}
		}
	}
}

AnimatedDrawableBehaviour* AnimatedDrawableBehaviour::EmptyClone()
{
	return new AnimatedDrawableBehaviour(renderer, sprite, screenWidth, screenHeight);
}
