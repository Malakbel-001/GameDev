#include "EnemyDrawableBehaviour.h"
#include "Entity.h"

EnemyDrawableBehaviour::EnemyDrawableBehaviour(SDL_Renderer* renderer, Sprite* _sprite, int screenwidth, int screenheight) : DrawableBehaviour(renderer, _sprite, screenwidth, screenheight)
{
}


EnemyDrawableBehaviour::~EnemyDrawableBehaviour()
{
}

void EnemyDrawableBehaviour::Draw()
{
	// Render current frame SCREEN SIZE NOT YET SET!!!
	float xpos = ((entity->GetXPos() / Ratio) - (camera->GetX() / Ratio)) + ((screenWidth / 2) - (screenWidth / 4));
	float ypos = entity->GetYPos() / Ratio;
	
	sprite->GetSpritesheet()->render(renderer, xpos, ypos, sprite->GetAnimationFrame(EntityState::IDLE, currentFrame));

	//Go to next frame 
	++currentFrame;

	//Cycle animation 
	if (currentFrame / sprite->GetAnimationSize() >= sprite->GetAnimationSize())
	{
		currentFrame = 0;
	}
}

EnemyDrawableBehaviour* EnemyDrawableBehaviour::EmptyClone()
{
	return new EnemyDrawableBehaviour(renderer, sprite, screenWidth, screenHeight);
}