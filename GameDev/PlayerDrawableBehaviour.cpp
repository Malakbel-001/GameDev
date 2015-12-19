#include "PlayerDrawableBehaviour.h"
#include "Entity.h"

PlayerDrawableBehaviour::PlayerDrawableBehaviour(SDL_Renderer* renderer, Sprite* _sprite, int screenwidth, int screenheight) : DrawableBehaviour(renderer, _sprite, screenwidth, screenheight)
{
	sprite->SetAnimationSet(EntityState::IDLE);
}


PlayerDrawableBehaviour::~PlayerDrawableBehaviour()
{
}

void PlayerDrawableBehaviour::Draw(bool cycle)
{
	if (entity->ShouldDraw()){
		// Render current frame SCREEN SIZE NOT YET SET!!!	
		float xpos = ((screenWidth / 2) - (screenWidth / 4));//( / Ratio) - (camera->GetX() / Ratio);
		float ypos = (entity->GetYpos() / Ratio);// - (camera->GetY() / Ratio);

		int size = sprite->GetAnimationSize(entity->GetState());
		if (currentFrame >= size) // /3
			currentFrame = 0;

		sprite->GetSpritesheet()->render(renderer, xpos, ypos, 0, sprite->GetAnimationFrame(entity->GetState(), currentFrame), entity->GetFlipped());

		//Go to next frame 
		if (cycle)
			++currentFrame;
	}
}

//void PlayerDrawableBehaviour::CycleFrames(bool cycle) {
//	if (cycle) {
//		int size = sprite->GetAnimationSize(entity->GetState()); // /3
//		//Cycle animation 
//
//		if (currentFrame >= size)
//		{
//			currentFrame = 0;
//		}
//
//		currentFrame++;
//	}
//}

PlayerDrawableBehaviour* PlayerDrawableBehaviour::EmptyClone()
{
	return new PlayerDrawableBehaviour(renderer, sprite, screenWidth, screenHeight);
}