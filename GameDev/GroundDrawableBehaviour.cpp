
#include "GroundDrawableBehaviour.h"
#include "Entity.h"


GroundDrawableBehaviour::GroundDrawableBehaviour(SDL_Renderer* renderer, Sprite* _sprite, int screenwidth, int screenheight) : DrawableBehaviour(renderer, _sprite, screenwidth, screenheight)
{
}


GroundDrawableBehaviour::~GroundDrawableBehaviour()
{
}



void GroundDrawableBehaviour::Draw()
{
	float xpos = ((entity->GetXPos() / Ratio) - (camera->GetX() / Ratio)) + ((screenWidth / 2) - (screenWidth / 4));
	float ypos = (entity->GetYPos() / Ratio);// - (camera->GetY() / Ratio)) + ((screenHeight / 2) + (screenHeight / 4));

	sprite->GetSpritesheet()->render(renderer, xpos, ypos, sprite->GetAnimationFrame(EntityState::DEFAULT, 0));		
}

GroundDrawableBehaviour* GroundDrawableBehaviour::EmptyClone()
{
	return new GroundDrawableBehaviour(renderer, sprite, screenWidth, screenHeight);
}