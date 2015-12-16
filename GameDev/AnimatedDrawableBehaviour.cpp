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
	if (entity->ShouldDraw()){
		// Render current frame SCREEN SIZE NOT YET SET!!!
		float xpos = ((entity->GetXpos() / Ratio) - (camera->GetX() / Ratio)) + ((screenWidth / 2) - (screenWidth / 4));
		float ypos = entity->GetYpos() / Ratio;

		ypos = ypos - sprite->GetFrameYOffSet(currentFrame );
		xpos = xpos - sprite->GetFrameXOffSet(currentFrame );


		sprite->GetSpritesheet()->render(renderer, xpos, ypos, (entity->GetAngle() * 90), sprite->GetAnimationFrame(entity->GetState(), currentFrame), entity->GetState());

		//Go to next frame 
		++currentFrame;
		int size = sprite->GetAnimationSize();
		//Cycle animation 

		if (currentFrame >= size)
		{
			currentFrame = 0;
		}
	}
}

AnimatedDrawableBehaviour* AnimatedDrawableBehaviour::EmptyClone()
{
	return new AnimatedDrawableBehaviour(renderer, sprite, screenWidth, screenHeight);
}
