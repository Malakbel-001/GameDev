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
	float xx = 1;
	float yy = 20;
	float ratio = (xx / yy);
	float xpos = entity->GetXPos() / ratio;
		float ypos = entity->GetYPos() / ratio;
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
		sprites.x = 515;
		sprites.y = 655;
		sprites.w = 128;
		sprites.h = 128;
	}
	return success;
}

GroundObstacleDrawableBehavior* GroundObstacleDrawableBehavior::EmptyClone()
{
	return new GroundObstacleDrawableBehavior(renderer, screenWidth, screenHeight);
}