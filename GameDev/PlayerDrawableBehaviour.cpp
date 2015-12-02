#include "PlayerDrawableBehaviour.h"
#include "Entity.h"

PlayerDrawableBehaviour::PlayerDrawableBehaviour(SDL_Renderer* renderer, Sprite* _sprite, int screenwidth, int screenheight) : DrawableBehaviour(renderer, _sprite, screenwidth, screenheight)
{
	sprite->SetAnimationSet(EntityState::IDLE);
}


PlayerDrawableBehaviour::~PlayerDrawableBehaviour()
{
}

void PlayerDrawableBehaviour::Draw()
{
	if (entity->ShouldDraw()){
		// Render current frame SCREEN SIZE NOT YET SET!!!	
		float xpos = ((screenWidth / 2) - (screenWidth / 4));//( / Ratio) - (camera->GetX() / Ratio);
		float ypos = (entity->GetYpos() / Ratio);// - (camera->GetY() / Ratio);

		sprite->GetSpritesheet()->render(renderer, xpos, ypos, 0, sprite->GetAnimationFrame(entity->GetState(), currentFrame/3));

		//Go to next frame 
		++currentFrame;
		int size = sprite->GetAnimationSize();
		//Cycle animation 

		if (currentFrame/3 >= size)
		{
			currentFrame = 0;
		}
	}
}

PlayerDrawableBehaviour* PlayerDrawableBehaviour::EmptyClone()
{
	return new PlayerDrawableBehaviour(renderer, sprite, screenWidth, screenHeight);
}