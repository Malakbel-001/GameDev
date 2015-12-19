#include "StaticDrawableBehaviour.h"
#include "Object.h"

StaticDrawableBehaviour::StaticDrawableBehaviour(SDL_Renderer* renderer, Sprite* _sprite, int screenwidth, int screenheight) : DrawableBehaviour(renderer, _sprite, screenwidth, screenheight)
{
}


StaticDrawableBehaviour::~StaticDrawableBehaviour()
{
}

void StaticDrawableBehaviour::Draw()
{
	if (entity->ShouldDraw()){
		float xpos = (((entity->GetXpos()) / Ratio) + sprite->GetXOffSet() - (camera->GetX() / Ratio)) + ((screenWidth / 2) - (screenWidth / 4));
		float ypos = (((entity->GetYpos()) / Ratio)) + sprite->GetYOffSet();// - (camera->GetY() / Ratio)) + ((screenHeight / 2) + (screenHeight / 4));

		sprite->GetSpritesheet()->render(renderer, xpos, ypos, (entity->GetAngle()*90), sprite->GetAnimationFrame(EntityState::DEFAULT, 0));
	}
}

StaticDrawableBehaviour* StaticDrawableBehaviour::EmptyClone()
{
	return new StaticDrawableBehaviour(renderer, sprite, screenWidth, screenHeight);
}