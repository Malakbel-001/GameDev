#include "StaticDrawableBehaviour.h"
#include "Entity.h"

StaticDrawableBehaviour::StaticDrawableBehaviour(SDL_Renderer* renderer, Sprite* _sprite, int screenwidth, int screenheight) : DrawableBehaviour(renderer, _sprite, screenwidth, screenheight)
{
}


StaticDrawableBehaviour::~StaticDrawableBehaviour()
{
}

void StaticDrawableBehaviour::Draw()
{
	float xpos = ((entity->GetXPos() / Ratio) - (camera->GetX() / Ratio)) + ((screenWidth / 2) - (screenWidth / 4));
	float ypos = (entity->GetYPos() / Ratio);// - (camera->GetY() / Ratio)) + ((screenHeight / 2) + (screenHeight / 4));

	sprite->GetSpritesheet()->render(renderer, xpos, ypos, sprite->GetAnimationFrame(EntityState::DEFAULT, 0));
}

StaticDrawableBehaviour* StaticDrawableBehaviour::EmptyClone()
{
	return new StaticDrawableBehaviour(renderer, sprite, screenWidth, screenHeight);
}