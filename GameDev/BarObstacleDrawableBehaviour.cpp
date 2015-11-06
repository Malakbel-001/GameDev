#include "BarObstacleDrawableBehaviour.h"
#include "Entity.h"


BarObstacleDrawableBehaviour::BarObstacleDrawableBehaviour(SDL_Renderer* renderer, int screenwidth, int screenheight) : DrawableBehaviour(renderer, screenwidth, screenheight)
{
	LoadMedia();
}


BarObstacleDrawableBehaviour::~BarObstacleDrawableBehaviour()
{
}



void BarObstacleDrawableBehaviour::Draw()
{

	float xpos = ((entity->GetXPos() / Ratio) - (camera->GetX() / Ratio)) + ((screenWidth / 2) - (screenWidth / 4));
	float ypos = (entity->GetYPos() / Ratio);// - (camera->GetY() / Ratio)) + ((screenHeight / 2) + (screenHeight / 4));
	spriteSheetTexture->render(renderer, xpos, ypos, &sprites);

}

void BarObstacleDrawableBehaviour::SetSprites(vector<SDL_Rect> sdl_sprites)
{

}

bool BarObstacleDrawableBehaviour::LoadMedia()
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
		sprites.x = 514;
		sprites.y = 527;
		sprites.w = 256;
		sprites.h = 10;
	}
	return success;
}

BarObstacleDrawableBehaviour* BarObstacleDrawableBehaviour::EmptyClone()
{
	return new BarObstacleDrawableBehaviour(renderer, screenWidth, screenHeight);
}

