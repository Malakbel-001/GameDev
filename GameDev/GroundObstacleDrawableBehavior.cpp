#include "GroundObstacleDrawableBehavior.h"
#include "Entity.h"


GroundObstacleDrawableBehavior::GroundObstacleDrawableBehavior(SDL_Renderer* renderer, int screenwidth, int screenheight) : DrawableBehaviour(renderer, screenwidth, screenheight)
{
	LoadMedia();
}


GroundObstacleDrawableBehavior::~GroundObstacleDrawableBehavior()
{
}

void GroundObstacleDrawableBehavior::Draw()
{
	
	float xpos = entity->GetXPos() / Ratio;
	float ypos = entity->GetYPos() / Ratio;
	spriteSheetTexture->render(renderer, xpos, ypos, &sprites);

}

void GroundObstacleDrawableBehavior::SetSprites(vector<SDL_Rect> sdl_sprites)
{

}

bool GroundObstacleDrawableBehavior::LoadMedia()
{
	//Loading success flag
	bool success = true;

	spritesheetPath = "";
	spritesheetName = "grass.png";

	//Load sprite sheet texture
	if (!spriteSheetTexture->loadFromFile(renderer, spritesheetPath + spritesheetName))
	{
		printf("Failed to load spritesheet! \n");
		success = false;
	}
	else
	{
		sprites.x = 280;
		sprites.y = 783;
		sprites.w = 137;
		sprites.h = 140;
	}
	return success;
}

GroundObstacleDrawableBehavior* GroundObstacleDrawableBehavior::EmptyClone()
{
	return new GroundObstacleDrawableBehavior(renderer, screenWidth, screenHeight);
}